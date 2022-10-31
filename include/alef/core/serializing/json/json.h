#ifndef ALEF_CORE_SERIALIZING_JSON_JSON_H
#define ALEF_CORE_SERIALIZING_JSON_JSON_H

#include "alef/concepts.h"
#include "alef/core/serializing/json/backing_data.h"

#include <initializer_list>
#include <iomanip>
#include <limits>
#include <sstream>

namespace alef::serializing {

class json {
    __json_detail::backing_data internal_{};

public:
    /// @brief
    enum class class_type {
        null,
        object,
        array,
        string,
        floating,
        integral,
        boolean
    };

private:
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

    json(std::initializer_list<json> list) :json{}
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
            this->internal_.json_map = new __json_detail::map_type{
                other.internal_.json_map->begin(),
                other.internal_.json_map->end()};
            break;
        case class_type::array:
            this->internal_.json_list = new __json_detail::list_type{
                other.internal_.json_list->begin(),
                other.internal_.json_list->end()};
            break;
        case class_type::string:
            this->internal_.json_string = new std::string{*other.internal_.json_string};
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
    template<concepts::logic::boolean T>
    explicit json(T value) : internal_{value}, type_{class_type::boolean}
    {
    }

    /// @brief Constructs from integral.
    template<concepts::numeric::integral T>
    explicit json(T value)
        : internal_{static_cast<std::int64_t>(value)}, type_{class_type::integral}
    {
    }

    /// @brief Constructs from floating.
    template<concepts::numeric::floating_point T>
    explicit json(T value)
        : internal_{static_cast<double>(value)}, type_{class_type::floating}
    {
    }

    /// @brief Constructs from floating.
    template<concepts::same_as<class_type> T>
    explicit json(T value) : type_{value}
    {
        switch (value) {
        case class_type::object:
            this->internal_.json_map = new __json_detail::map_type{};
            break;
        case class_type::array:
            this->internal_.json_list = new __json_detail::list_type{};
            break;
        case class_type::string:
            this->internal_.json_string = new std::string{};
            break;
        }
    }

    /// @brief Constructs from string.
    template<concepts::convertible_to<std::string> T>
    explicit json(T value) : internal_{std::string{value}}, type_{class_type::string}
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
            this->internal_.json_map = new __json_detail::map_type{
                other.internal_.json_map->begin(),
                other.internal_.json_map->end()};
            break;
        case class_type::array:
            this->internal_.json_list = new __json_detail::list_type{
                other.internal_.json_list->begin(),
                other.internal_.json_list->end()};
            break;
        case class_type::string:
            this->internal_.json_string = new std::string{*other.internal_.json_string};
            break;
        default:
            this->internal_ = other.internal_;
            break;
        }
        this->type_ = other.type_;
        return *this;
    }

    template<std::same_as<bool> T>
    json& operator=(T b) &
    {
        set_type(class_type::boolean);
        this->internal_.json_bool = b;
        return *this;
    }

    template<typename T>
    requires std::integral<T> && (!std::same_as<T, bool>)
    json& operator=(T i) &
    {
        set_type(class_type::integral);
        this->internal_.json_int = i;
        return *this;
    }

    template<std::floating_point T>
    json& operator=(T f) &
    {
        set_type(class_type::floating);
        this->internal_.json_float = f;
        return *this;
    }

    template<std::convertible_to<std::string> T>
    json& operator=(T s) &
    {
        set_type(class_type::string);
        *this->internal_.json_string = std::string{s};
        return *this;
    }

    json& operator[](const std::string& key) &
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

    static json load(const std::string& value)
    {
        std::size_t offset{};
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
    const json& at(const std::string& key) const
    {
        return this->internal_.json_map->at(key);
    }

    json& at(const std::string& key)
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
    std::size_t length() const
    {
        return (this->type_ == class_type::array)
               ? this->internal_.json_list->size()
               : std::numeric_limits<std::size_t>::max();
    }

    [[nodiscard]]
    bool has_key(const std::string& key) const
    {
        return (this->type_ == class_type::object) &&
            (this->internal_.json_map->find(key) != this->internal_.json_map->end());
    }

    [[nodiscard]]
    std::size_t size() const
    {
        switch (this->type_) {
        case class_type::object:
            return this->internal_.json_map->size();
        case class_type::array:
            return this->internal_.json_list->size();
        default:
            return std::numeric_limits<std::size_t>::max();
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
    std::string to_string() const
    {
        return to_string(bool{});
    }

    std::string to_string(bool&& ok) const
    {
        return (ok = this->type_ == class_type::string)
               ? json_escape(*this->internal_.json_string)
               : std::string{};
    }

    [[nodiscard]]
    double to_float() const
    {
        return to_float({});
    }

    double to_float(bool&& ok) const
    {
        return (ok = this->type_ == class_type::floating) ? this->internal_.json_float : double{};
    }

    [[nodiscard]]
    std::int64_t to_int() const
    {
        return to_int({});
    }

    std::int64_t to_int(bool&& ok) const
    {
        return (ok = this->type_ == class_type::integral)
            ? this->internal_.json_int
            : __json_detail::int_type{};
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
               ? __json_detail::const_list_wrapper_type{this->internal_.json_list}
               : __json_detail::const_list_wrapper_type{nullptr};
    }

    auto array_range()
    {
        return (this->type_ == class_type::array)
               ? __json_detail::list_wrapper_type{this->internal_.json_list}
               : __json_detail::list_wrapper_type{nullptr};
    }

    [[nodiscard]]
    auto object_range() const
    {
        return (this->type_ == class_type::array)
               ? __json_detail::const_map_wrapper_type{this->internal_.json_map}
               : __json_detail::const_map_wrapper_type{nullptr};
    }

    auto object_range()
    {
        return (this->type_ == class_type::object)
               ? __json_detail::map_wrapper_type{this->internal_.json_map}
               : __json_detail::map_wrapper_type{nullptr};
    }

    [[nodiscard]]
    std::string dump(int depth = 1, const std::string& tab = "    ") const
    {
        std::string padding;
        for (int i = 0; i < depth; ++i, padding += tab) { }

        std::stringstream ss;

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

    static std::string json_escape(const std::string& value)
    {
        std::stringstream ss;

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
            this->internal_.json_map = new __json_detail::map_type{};
            break;
        case class_type::array:
            this->internal_.json_list = new __json_detail::list_type{};
            break;
        case class_type::string:
            this->internal_.json_string = new std::string{};
            break;
        case class_type::floating:
            this->internal_.json_float = double{};
            break;
        case class_type::integral:
            this->internal_.json_int = __json_detail::int_type{};
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
    static void consume_ws(const std::string& str, std::size_t& offset)
    {
        while (isspace(str[offset])) ++offset;
    }

    static json parse_next(const std::string& str, std::size_t& offset)
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
        std::stringstream ss;
        ss << "unknown starting character: '" << value << '\'';

        throw std::invalid_argument{ss.str()};
    }

    static json parse_object(const std::string& str, std::size_t& offset)
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
                std::stringstream ss;
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
                std::stringstream ss;
                ss << "expected ',', found: '" << str[offset] << '\'';

                throw std::invalid_argument{ss.str()};
            }
        }
        return json_object;
    }

    static json parse_array(const std::string& str, std::size_t& offset)
    {
        auto json_array = json(class_type::array);
        std::size_t index{};

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
                std::stringstream ss;
                ss << "expected ',' or ']', found: '" << str[offset] << '\'';

                throw std::invalid_argument{ss.str()};
            }
        }
        return json_array;
    }

    static json parse_string(const std::string& str, std::size_t& offset)
    {
        json json_string;
        std::stringstream ss;

        std::string value;

        for (char c = str[++offset]; c != '\"'; c = str[++offset]) {
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
                for (unsigned i = 1; i <= 4; ++i) {
                    c = str[offset + i];

                    if (((c >= '0') && (c <= '9')) || ((c >= 'a') && (c <= 'f')) ||
                        ((c >= 'A') && (c <= 'F')))
                    {
                        ss << c;
                    }
                    else {
                        std::stringstream es;
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

    static json parse_number(const std::string& str, std::size_t& offset)
    {
        json number;
        std::stringstream ss;
        std::stringstream expression_value;
        char c;
        bool is_floating{};
        __json_detail::int_type exp{};

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
                expression_value << '-';
            }
            while (true) {
                c = str[offset++];

                if (c >= '0' && c <= '9') {
                    expression_value << c;
                }
                else if (!isspace(c) && (c != ',') && (c != ']') && (c != '}')) {
                    std::stringstream es;
                    es << "expected a number for exponent, found: '" << c << '\'';

                    throw std::invalid_argument{es.str()};
                }
                else {
                    break;
                }
            }
            exp = std::stoll(expression_value.str());
        }
        else if (!isspace(c) && (c != ',') && (c != ']') && (c != '}')) {
            std::stringstream es;
            es << "unexpected character: " << c << '\'';

            throw std::invalid_argument{es.str()};
        }
        --offset;

        if (is_floating) {
            number = std::stod(ss.str()) * std::pow(10, exp);
        }
        else {
            number = (!expression_value.str().empty())
                ? static_cast<__json_detail::float_type>(std::stoll(ss.str())) * std::pow(10, exp)
                : static_cast<__json_detail::float_type>(std::stoll(ss.str()));
        }
        return number;
    }

    static json parse_bool(const std::string& str, std::size_t& offset)
    {
        json json_bool;

        if (str.substr(offset, 4) == "true") {
            json_bool = true;
        }
        else if (str.substr(offset, 5) == "false") {
            json_bool = false;
        }
        else {
            std::stringstream ss;
            ss << "expected 'true' or 'false', found: " << str.substr(offset, 5) << '\'';

            throw std::invalid_argument{ss.str()};
        }
        offset += json_bool.to_bool() ? 4 : 5;
        return json_bool;
    }

    static json parse_null(const std::string& str, std::size_t& offset)
    {
        json json_null;

        if (str.substr(offset, 4) != "null") {
            std::stringstream ss;
            ss << "expected 'null', found: '" << str.substr(offset, 4) << '\'';

            throw std::invalid_argument{ss.str()};
        }
        offset += 4;
        return json_null;
    }
};

} // namespace alef::serializing

#endif // ALEF_CORE_SERIALIZING_JSON_JSON_H
