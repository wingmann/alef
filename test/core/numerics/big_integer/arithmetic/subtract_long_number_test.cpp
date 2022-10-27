#include "alef/core/numerics/big_integer.h"

#include <gtest/gtest.h>

using namespace alef::numerics;

TEST(alef_core_numerics_biginteger_arithmetic, subtract_1)
{
    big_integer a{"389323749846515441868468446416417872"};
    big_integer b{"9079798797979780928312678"};

    EXPECT_EQ(a - b, "389323749837435643070488665488105194");
}

TEST(alef_core_numerics_biginteger_arithmetic, subtract_2)
{
    big_integer a{"23749846515441868468446416417872716414841861868188616541687871686188"};
    big_integer b{"23749846515441868468446416417872716414841861868188616541687871686183"};

    EXPECT_EQ(a - b, 5);
}

TEST(alef_core_numerics_biginteger_arithmetic, subtract_negative)
{
    big_integer a{"-134684987024161489187436113184467664684"};
    big_integer b{"-23749846515441868468446416417872716414841861868188616541687871686183"};

    EXPECT_EQ(a - b, "23749846515441868468446416417738031427817700379001180428503404021499");
}

TEST(alef_core_numerics_biginteger_arithmetic, subtract_big_nubers)
{
    big_integer a =
        "461848481646846848464811468486464282146814684841848648648484894484842982419848949889294189"
        "164842894898919849892884289289489891489482819848949824298439849849788123892498438948348384"
        "879884198128489484389494294894849800391371301984646146141896481640804601419458667398173872"
        "897479079824602840607267463246034786786478283748764862378487268432746238704234627846189113"
        "89729837972371738129837239818237712839173872389712893712893891238712387128931273317907293";

    big_integer b =
        "901731983182639861263921636237612767141715861517184984984982894989819846021487199798897427"
        "384728341894689641289463621486238641889268964892368496238468293684621384629426982526598165"
        "983269818235631658295821983217312893748278926441842893842984518942989498432449741989882848"
        "748920484724891419824298498418419842928984983249849841981498298419848949828189489498498228"
        "24984149829849848981994284894198492498419849849214942984984198984924720484962642647732462";

    auto expected =
        "-43988350153579301279911016775114848499490117667533633633649800050497686360163824990960323"
        "821988544699576979139657933219674875039978614504341867194002844383483326073692854357824978"
        "110338562010714217390632768832246309335690762445719674770108803730218489701299107459170897"
        "585144140490028857921703103517238505614250669950108497960301102998710271112395486165230911"
        "43525431185747811085215704507596077965924597745950204927209030774621233335603136932982"
        "5169";

    EXPECT_EQ(a - b, expected);
}
