#include <alef/core/error/result.h>

#include <gtest/gtest.h>

#include <utility>

using namespace alef::error;

struct logic_error {
public:
    enum class kind { invalid_argument, out_of_range };

private:
    kind kind_;
    std::string message_;

public:
    logic_error(kind value, std::string msg) : kind_{value}, message_{std::move(msg)} { }

public:
    [[nodiscard]]
    kind get() const { return kind_; }

    [[nodiscard]]
    std::string what() const { return message_; }
};

result<int, logic_error> convert_to_int(const std::string& value)
{
    try {
        return ok(std::stoi(value));
    }
    catch (std::invalid_argument&) {
        return err(logic_error{logic_error::kind::invalid_argument, "invalid argument"});
    }
    catch (std::out_of_range&) {
        return err(logic_error{logic_error::kind::out_of_range, "out of range"});
    }
}

TEST(alef_core_error, handling_error_1)
{
    auto number = convert_to_int("ERR1024");
    if (number.is_err()) {
        switch (number.unwrap_err().get()) {
        case logic_error::kind::invalid_argument:
            EXPECT_EQ(number.unwrap_err().what(), "invalid argument");
            break;
        default:
            break;
        }
    }
}

TEST(alef_core_error, handling_error_2)
{
    auto number = convert_to_int("99999999999999");
    if (number.is_err()) {
        switch (number.unwrap_err().get()) {
        case logic_error::kind::out_of_range:
            EXPECT_EQ(number.unwrap_err().what(), "out of range");
            break;
        default:
            EXPECT_TRUE(false);
            break;
        }
    }
}

TEST(alef_core_error, using_correct)
{
    auto number = convert_to_int("1024");
    if (number.is_ok())
        EXPECT_EQ(number.unwrap(), 1024);
    else
        EXPECT_TRUE(false);
}
