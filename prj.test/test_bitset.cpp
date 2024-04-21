#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "bitset/bitset.hpp"

TEST_CASE("bitset ctor") {
    BitSet bs1(5);
    BitSet bs2(5);

    SUBCASE("Testing operator== and operator!=") {
        CHECK((bs1 == bs2));
        bs1.Set(0, true);
        CHECK((bs1 != bs2));
    }

    SUBCASE("Testing Resize") {
        bs1.Resize(10);
        CHECK(bs1.Size() == 10);
    }

    SUBCASE("Testing Get and Set") {
        bs1.Set(0, true);
        CHECK(bs1.Get(0) == true);
    }

    SUBCASE("Testing Fill") {
        bs1.Fill(true);
        for (int i = 0; i < bs1.Size(); ++i) {
            CHECK(bs1.Get(i) == true);
        }
    }

    SUBCASE("Testing operator~") {
        bs1.Fill(true);
        bs1 = ~bs1;
        for (int i = 0; i < bs1.Size(); ++i) {
            CHECK(bs1.Get(i) == false);
        }
    }

    SUBCASE("Testing operator|=") {
        bs1.Set(0, true);
        bs2.Set(1, true);
        bs1 |= bs2;
        CHECK(bs1.Get(0) == true);
        CHECK(bs1.Get(1) == true);
    }

    SUBCASE("Testing operator&=") {
        bs1.Set(0, true);
        bs1.Set(1, true);
        bs2.Set(1, true);
        bs1 &= bs2;
        CHECK(bs1.Get(0) == false);
        CHECK(bs1.Get(1) == true);
    }

    SUBCASE("Testing operator^=") {
        bs1.Set(0, true);
        bs2.Set(0, true);
        bs1 ^= bs2;
        CHECK(bs1.Get(0) == false);
    }
}
