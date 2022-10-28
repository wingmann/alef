#include <alef/core/serializing/json.h>

#include <gtest/gtest.h>

using namespace alef::serializing;

TEST(jsonlw, dump) {
    json obj;
    obj["array"] = json::array(true, "two", 3, 4.0);
    obj["obj"] = json::object();
    obj["obj"]["inner"] = "inside";
    obj["new"]["some"]["deep"]["key"] = "value";
    obj["array2"].append(false, "three");
    obj["parsed"] = json::load(R"([{"key": "value"}, false])");

    auto dump = obj.dump();
    std::cout << dump << "\n\n";

    EXPECT_TRUE(true);
}

TEST(jsonlw, load) {
    json obj = json::load(R"(
    {
        "array": [true, "two", 3, 4.000000],
        "array2": [false, "three"],
        "new": {
            "some": {
                "deep": {
                    "key": "value"
                }
            }
        },
        "obj": {
            "inner": "inside"
        },
        "parsed": [
            { "key": "value" },
            false
        ]
    })");

    auto dump = obj.dump();
    std::cout << dump << "\n\n";

    EXPECT_TRUE(true);
}
