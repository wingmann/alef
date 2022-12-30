#include <alef/alef.h>
#include <alef/io.h>
#include <alef/lib/serializing/json.h>

#include <gtest/gtest.h>

using namespace alf::serializing;

TEST(alef_lib_serializing_json, dump)
{
    json obj;
    obj["array"] = json::array(true, "two", 3, 4.0);
    obj["obj"] = json::object();
    obj["obj"]["inner"] = "inside";
    obj["new"]["some"]["deep"]["key"] = "value";
    obj["array2"].append(false, "three");
    obj["parsed"] = json::load(R"([{"key": "value"}, false])");

    alf::io_stdout out;
    out.print << obj.dump() << "\n\n";

    EXPECT_TRUE(true);
}

TEST(alef_lib_serializing_json, load)
{
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

    alf::io_stdout out;
    out.print << obj.dump() << "\n\n";

    EXPECT_TRUE(true);
}
