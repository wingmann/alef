#ifndef ALEF_CORE_SERIALIZING_JSON_JSON_H
#define ALEF_CORE_SERIALIZING_JSON_JSON_H

#include "alef/alef.h"
#include "alef/core/string/string.h"
#include "alef/core/string/string_stream.h"
#include "alef/core/types/serializing/json.h"
#include "alef/lib/concepts/general.h"
#include "alef/lib/serializing/json/__detail/backing_data.h"

#include <initializer_list>
#include <iomanip>
#include <limits>

namespace alf::serializing {

class json {
public:
    using class_type = alf::types::serializing::json_class;

private:
    alf::serializing::__detail::json::backing_data internal_{};
    class_type type_{class_type::null};

public:
    json() = default;

    virtual ~json()
    {
        switch (type_) {
        case class_type::array:
            delete internal_.json_list;
            break;
        case class_type::object:
            delete internal_.json_map;
            break;
        case class_type::string:
            delete internal_.json_string;
            break;
        default:
            break;
        }
    }

    json(std::initializer_list<json> list) : json{}
    {
        set_type(class_type::object);

        for (auto it = list.begin(), end = list.end(); it != end; ++it)
            operator[](it->to_string()) = *std::next(it);
    }

    json(json&& other) noexcept :internal_{other.internal_}, type_{other.type_}
    {
        other.type_ = class_type::null;
        other.internal_.json_map = nullptr;
    }

    json(const json& other)
    {
        switch (other.type_) {
        case class_type::object:
            this->internal_.json_map = new alf::serializing::__detail::json::map_type{
                other.internal_.json_map->begin(),
                other.internal_.json_map->end()};
            break;
        case class_type::array:
            this->internal_.json_list = new alf::serializing::__detail::json::list_type{
                other.internal_.json_list->begin(),
                other.internal_.json_list->end()};
            break;
        case class_type::string:
            this->internal_.json_string = new alf::string{*other.internal_.json_string};
            break;
        default:
            this->internal_ = other.internal_;
            break;
        }
        this->type_ = other.type_;
    }

    explicit json(std::nullptr_t) : internal_{}, type_{class_type::null}
    {
    }

    /// @brief Constructs from boolean.
    template<alf::concepts::boolean T>
    explicit json(T value) : internal_{value}, type_{class_type::boolean}
    {
    }

    /// @brief Constructs from integral.
    template<alf::concepts::integral T>
    explicit json(T value)
        : internal_{static_cast<alf::i64>(value)}, type_{class_type::integral}
    {
    }

    /// @brief Constructs from floating.
    template<alf::concepts::floating_point T>
    explicit json(T value)
        : internal_{static_cast<alf::f64>(value)}, type_{class_type::floating}
    {
    }

    /// @brief Constructs from floating.
    template<alf::concepts::same_as<class_type> T>
    explicit json(T value) : type_{value}
    {
        switch (value) {
        case class_type::object:
            this->internal_.json_map = new alf::serializing::__detail::json::map_type{};
            break;
        case class_type::array:
            this->internal_.json_list = new alf::serializing::__detail::json::list_type{};
            break;
        case class_type::string:
            this->internal_.json_string = new alf::string{};
            break;
        default:
            break;
        }
    }

    /// @brief Constructs from string.
    template<alf::concepts::convertible_to<alf::string> T>
    explicit json(T value) : internal_{alf::string{value}}, type_{class_type::string}
    {
    }

    // Operators.
    json& operator=(json&& other) & noexcept
    {
        clear_internal();

        this->internal_ = other.internal_;
        this->type_ = other.type_;

        other.internal_.json_map = nullptr;
        other.type_ = class_type::null;

        return *this;
    }

    json& operator=(const json& other) &
    {
        clear_internal();

        switch (other.type_) {
        case class_type::object:
            this->internal_.json_map = new alf::serializing::__detail::json::map_type{
                other.internal_.json_map->begin(),
                other.internal_.json_map->end()};
            break;
        case class_type::array:
            this->internal_.json_list = new alf::serializing::__detail::json::list_type{
                other.internal_.json_list->begin(),
                other.internal_.json_list->end()};
            break;
        case class_type::string:
            this->internal_.json_string = new alf::string{*other.internal_.json_string};
            break;
        default:
            this->internal_ = other.internal_;
            break;
        }
        this->type_ = other.type_;
        return *this;
    }

    template<alf::concepts::same_as<bool> T>
    json& operator=(T b) &
    {
        set_type(class_type::boolean);
        this->internal_.json_bool = b;
        return *this;
    }

    template<typename T>
    requires alf::concepts::integral<T> && (!alf::concepts::same_as<T, bool>)
    json& operator=(T i) &
    {
        set_type(class_type::integral);
        this->internal_.json_int = i;
        return *this;
    }

    template<alf::concepts::floating_point T>
    json& operator=(T f) &
    {
        set_type(class_type::floating);
        this->internal_.json_float = f;
        return *this;
    }

    template<alf::concepts::convertible_to<alf::string> T>
    json& operator=(T s) &
    {
        set_type(class_type::string);
        *this->internal_.json_string = alf::string{s};
        return *this;
    }

    json& operator[](const alf::string& key) &
    {
        set_type(class_type::object);
        return this->internal_.json_map->operator[](key);
    }

    json& operator[](unsigned index) &
    {
        set_type(class_type::array);
        if (index >= this->internal_.json_list->size())
            this->internal_.json_list->resize(index + 1);

        return this->internal_.json_list->operator[](index);
    }

    // Methods.
    static json make(class_type type)
    {
        json ret;
        ret.set_type(type);
        return ret;
    }

    static json load(const alf::string& value)
    {
        alf::usize offset{};
        return parse_next(value, offset);
    }

    template<typename T>
    void append(T arg)
    {
        set_type(class_type::array);
        this->internal_.json_list->emplace_back(arg);
    }

    template<typename T, typename... U>
    void append(T arg, U ...args)
    {
        append(arg);
        append(args...);
    }

    [[nodiscard]]
    const json& at(const alf::string& key) const
    {
        return this->internal_.json_map->at(key);
    }

    json& at(const alf::string& key)
    {
        return operator[](key);
    }

    [[nodiscard]]
    const json& at(unsigned index) const
    {
        return this->internal_.json_list->at(index);
    }

    json& at(unsigned index)
    {
        return operator[](index);
    }

    [[nodiscard]]
    alf::usize length() const
    {
        return (this->type_ == class_type::array)
            ? this->internal_.json_list->size()
            : std::numeric_limits<alf::usize>::max();
    }

    [[nodiscard]]
    bool has_key(const alf::string& key) const
    {
        return (this->type_ == class_type::object) &&
            (this->internal_.json_map->find(key) != this->internal_.json_map->end());
    }

    [[nodiscard]]
    alf::usize size() const
    {
        switch (this->type_) {
        case class_type::object:
            return this->internal_.json_map->size();
        case class_type::array:
            return this->internal_.json_list->size();
        default:
            return std::numeric_limits<alf::usize>::max();
        }
    }

    [[nodiscard]]
    class_type json_type() const
    {
        return this->type_;
    }

    // Functions for getting primitives from the json object.
    [[nodiscard]]
    bool is_null() const
    {
        return this->type_ == class_type::null;
    }

    [[nodiscard]]
    alf::string to_string() const
    {
        return to_string(bool{});
    }

    alf::string to_string(bool&& ok) const
    {
        return (ok = this->type_ == class_type::string)
            ? json_escape(*this->internal_.json_string)
            : alf::string{};
    }

    [[nodiscard]]
    double to_float() const
    {
        return to_float({});
    }

    double to_float(bool&& ok) const
    {
        return (ok = this->type_ == class_type::floating)
            ? this->internal_.json_float
            : alf::f64{};
    }

    [[nodiscard]]
    alf::i64 to_int() const
    {
        return to_int({});
    }

    alf::i64 to_int(bool&& ok) const
    {
        return (ok = this->type_ == class_type::integral)
            ? this->internal_.json_int
            : alf::serializing::__detail::json::int_type{};
    }

    [[nodiscard]]
    bool to_bool() const
    {
        return to_bool({});
    }

    bool to_bool(bool&& ok) const
    {
        return (ok = this->type_ == class_type::boolean) && this->internal_.json_bool;
    }

    [[nodiscard]]
    auto array_range() const
    {
        return (this->type_ == class_type::array)
            ? alf::serializing::__detail::json::const_list_wrapper_type{this->internal_.json_list}
            : alf::serializing::__detail::json::const_list_wrapper_type{nullptr};
    }

    auto array_range()
    {
        return (this->type_ == class_type::array)
            ? alf::serializing::__detail::json::list_wrapper_type{this->internal_.json_list}
            : alf::serializing::__detail::json::list_wrapper_type{nullptr};
    }

    [[nodiscard]]
    auto object_range() const
    {
        return (this->type_ == class_type::array)
            ? alf::serializing::__detail::json::const_map_wrapper_type{this->internal_.json_map}
            : alf::serializing::__detail::json::const_map_wrapper_type{nullptr};
    }

    auto object_range()
    {
        return (this->type_ == class_type::object)
            ? alf::serializing::__detail::json::map_wrapper_type{this->internal_.json_map}
            : alf::serializing::__detail::json::map_wrapper_type{nullptr};
    }

    [[nodiscard]]
    alf::string dump(int depth = 1, const alf::string& tab = "    ") const
    {
        alf::string padding;
        for (auto i = 0_i32; i < depth; ++i, padding += tab) { }

        alf::string_stream ss;

        switch (type_) {
        case class_type::object:
        {
            ss << "{\n";
            bool skip{true};

            for (auto& p : *this->internal_.json_map) {
                if (!skip) ss << ",\n";

                ss << padding << std::quoted(p.first) << ": " << p.second.dump(depth + 1, tab);
                skip = false;
            }
            ss << '\n' << padding.erase(0, tab.length()) << '}';
            return ss.str();
        }
        case class_type::array:
        {
            ss << '[';
            bool skip{true};

            for (auto& p : *this->internal_.json_list) {
                if (!skip) ss << ", ";
                ss << p.dump(depth + 1, tab);
                skip = false;
            }
            ss << ']';
            return ss.str();
        }
        case class_type::string:
            ss << std::quoted(json_escape(*this->internal_.json_string));
            return ss.str();
        case class_type::floating:
            ss << std::to_string(this->internal_.json_float);
            return ss.str();
        case class_type::integral:
            ss << std::to_string(this->internal_.json_int);
            return ss.str();
        case class_type::boolean:
            ss << (this->internal_.json_bool ? "true" : "false");
            return ss.str();
        default:
            return "null";
        }
    }

    std::ostream& operator<<(std::ostream& os) const
    {
        os << this->dump();
        return os;
    }

    template<typename... T>
    static json array(T... args)
    {
        json arr = json(class_type::array);
        arr.append(args...);
        return arr;
    }

    static json array()
    {
        return json(class_type::array);
    }

    static json object()
    {
        return json(class_type::object);
    }

    static alf::string json_escape(const alf::string& value)
    {
        alf::string_stream ss;

        for (const char& i : value) {
            switch (i) {
            case '\"': ss << "\\\""; break;
            case '\\': ss << "\\\\"; break;
            case '\b': ss << "\\b";  break;
            case '\f': ss << "\\f";  break;
            case '\n': ss << "\\n";  break;
            case '\r': ss << "\\r";  break;
            case '\t': ss << "\\t";  break;
            default:   ss << i;      break;
            }
        }
        return ss.str();
    }

private:
    void set_type(class_type type)
    {
        if (type == this->type_) return;
        clear_internal();

        switch (type) {
        case class_type::null:
            this->internal_.json_map = nullptr;
            break;
        case class_type::object:
            this->internal_.json_map = new alf::serializing::__detail::json::map_type{};
            break;
        case class_type::array:
            this->internal_.json_list = new alf::serializing::__detail::json::list_type{};
            break;
        case class_type::string:
            this->internal_.json_string = new alf::string{};
            break;
        case class_type::floating:
            this->internal_.json_float = alf::f64{};
            break;
        case class_type::integral:
            this->internal_.json_int = alf::serializing::__detail::json::int_type{};
            break;
        case class_type::boolean:
            this->internal_.json_bool = false;
            break;
        }
        this->type_ = type;
    }

    /// @warning Only call if you know that Internal is allocated.
    /// No checks performed here.
    /// This function should be called in a constructed json just before you are going to
    /// overwrite internal.
    void clear_internal()
    {
        switch (type_) {
        case class_type::object: delete this->internal_.json_map;    break;
        case class_type::array:  delete this->internal_.json_list;   break;
        case class_type::string: delete this->internal_.json_string; break;
        default: break;
        }
    }

public:
    static void consume_ws(const alf::string& str, alf::usize& offset)
    {
        while (isspace(str[offset])) ++offset;
    }

    static json parse_next(const alf::string& str, alf::usize& offset)
    {
        char value;
        consume_ws(str, offset);
        value = str[offset];

        switch (value) {
        case '[':  return parse_array(str, offset);
        case '{':  return parse_object(str, offset);
        case '\"': return parse_string(str, offset);
        case 't':
        case 'f':  return parse_bool(str, offset);
        case 'n':  return parse_null(str, offset);
        default:
            if (((value <= '9') && (value >= '0')) || (value == '-'))
                return parse_number(str, offset);
        }
        alf::string_stream ss;
        ss << "unknown starting character: '" << value << '\'';

        throw std::invalid_argument{ss.str()};
    }

    static json parse_object(const alf::string& str, alf::usize& offset)
    {
        auto json_object = json(class_type::object);

        ++offset;
        consume_ws(str, offset);

        if (str[offset] == '}') {
            ++offset;
            return json_object;
        }

        while (true)         {
            auto key = parse_next(str, offset);
            consume_ws(str, offset);

            if (str[offset] != ':') {
                alf::string_stream ss;
                ss << "expected ':', found: '" << str[offset] << '\'';

                throw std::invalid_argument{ss.str()};
            }
            consume_ws(str, ++offset);
            auto value = parse_next(str, offset);
            json_object[key.to_string()] = value;
            consume_ws(str, offset);

            if (str[offset] == ',') {
                ++offset;
                continue;
            }
            else if (str[offset] == '}') {
                ++offset;
                break;
            }
            else {
                alf::string_stream ss;
                ss << "expected ',', found: '" << str[offset] << '\'';

                throw std::invalid_argument{ss.str()};
            }
        }
        return json_object;
    }

    static json parse_array(const alf::string& str, alf::usize& offset)
    {
        auto json_array = json(class_type::array);
        alf::usize index{};

        ++offset;
        consume_ws(str, offset);

        if (str[offset] == ']') {
            ++offset;
            return json_array;
        }
        while (true) {
            json_array[index++] = parse_next(str, offset);
            consume_ws(str, offset);

            if (str[offset] == ',') {
                ++offset;
                continue;
            }
            else if (str[offset] == ']') {
                ++offset;
                break;
            }
            else {
                alf::string_stream ss;
                ss << "expected ',' or ']', found: '" << str[offset] << '\'';

                throw std::invalid_argument{ss.str()};
            }
        }
        return json_array;
    }

    static json parse_string(const alf::string& str, alf::usize& offset)
    {
        json json_string;
        alf::string_stream ss;

        alf::string value;

        for (auto c = str[++offset]; c != '\"'; c = str[++offset]) {
            if (c != '\\') {
                ss << c;
                continue;
            }

            switch (str[++offset]) {
            case '\"': ss << '\"'; break;
            case '\\': ss << '\\'; break;
            case '/':  ss << '/';  break;
            case 'b':  ss << '\b'; break;
            case 'f':  ss << '\f'; break;
            case 'n':  ss << '\n'; break;
            case 'r':  ss << '\r'; break;
            case 't':  ss << '\t'; break;
            case 'u':
            {
                ss << "\\u";
                for (auto i = 1_ui32; i <= 4; ++i) {
                    c = str[offset + i];

                    auto correct =
                        (((c >= '0') && (c <= '9')) ||
                         ((c >= 'a') && (c <= 'f')) ||
                         ((c >= 'A') && (c <= 'F')));

                    if (correct) {
                        ss << c;
                    }
                    else {
                        alf::string_stream es;
                        es << "expected hex character in unicode escape, found: '" << c << '\'';

                        throw std::invalid_argument{es.str()};
                    }
                }
                offset += 4;
                break;
            }
            default:
                ss << '\\';
                break;
            }
        }
        ++offset;
        json_string = ss.str();
        return json_string;
    }

    static json parse_number(const alf::string& str, alf::usize& offset)
    {
        json number;
        alf::string_stream ss;
        alf::string_stream expr_value;
        char c;
        bool is_floating{};
        alf::serializing::__detail::json::int_type exp{};

        while (true) {
            if (c = str[offset++]; (c == '-') || ((c >= '0') && (c <= '9'))) {
                ss << c;
            }
            else if (c == '.') {
                ss << c;
                is_floating = true;
            }
            else {
                break;
            }
        }

        if (c == 'E' || c == 'e') {
            c = str[offset++];

            if (c == '-') {
                ++offset;
                expr_value << '-';
            }
            while (true) {
                c = str[offset++];

                if (c >= '0' && c <= '9') {
                    expr_value << c;
                }
                else if (!isspace(c) && (c != ',') && (c != ']') && (c != '}')) {
                    alf::string_stream es;
                    es << "expected a number for exponent, found: '" << c << '\'';

                    throw std::invalid_argument{es.str()};
                }
                else {
                    break;
                }
            }
            exp = std::stoll(expr_value.str());
        }
        else if (!isspace(c) && (c != ',') && (c != ']') && (c != '}')) {
            alf::string_stream es;
            es << "unexpected character: " << c << '\'';

            throw std::invalid_argument{es.str()};
        }
        --offset;

        if (is_floating) {
            number = std::stod(ss.str()) * std::pow(10, exp);
        }
        else {
            if (!expr_value.str().empty()) {
                number = static_cast<alf::serializing::__detail::json::float_type>(
                    std::stoll(ss.str())) *
                        std::pow(10, exp);
            }
            else {
                number = static_cast<alf::serializing::__detail::json::float_type>(
                    std::stoll(ss.str()));
            }
        }
        return number;
    }

    static json parse_bool(const alf::string& str, alf::usize& offset)
    {
        json json_bool;

        if (str.substr(offset, 4) == "true") {
            json_bool = true;
        }
        else if (str.substr(offset, 5) == "false") {
            json_bool = false;
        }
        else {
            alf::string_stream ss;
            ss << "expected 'true' or 'false', found: " << str.substr(offset, 5) << '\'';

            throw std::invalid_argument{ss.str()};
        }
        offset += json_bool.to_bool() ? 4 : 5;
        return json_bool;
    }

    static json parse_null(const alf::string& str, alf::usize& offset)
    {
        json json_null;

        if (str.substr(offset, 4) != "null") {
            alf::string_stream ss;
            ss << "expected 'null', found: '" << str.substr(offset, 4) << '\'';

            throw std::invalid_argument{ss.str()};
        }
        offset += 4;
        return json_null;
    }
};

} // namespace alf::serializing

#endif // ALEF_CORE_SERIALIZING_JSON_JSON_H
