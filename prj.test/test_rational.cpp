#include <rational/rational.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

bool testParse(const std::string& str) {
    std::istringstream istrm(str);
    Rational z;
    istrm >> z;
    return istrm.good();
}

TEST_CASE("rational ctor") {
    Rational r_def;
    CHECK(0 == r_def.num());
    CHECK(1 == r_def.den());

    Rational r_int(3);
    CHECK(3 == r_int.num());
    CHECK(1 == r_int.den());

    Rational two_int(3, 5);
    CHECK(3 == two_int.num());
    CHECK(5 == two_int.den());

    Rational cutback(3, 9);
    CHECK(1 == cutback.num());
    CHECK(3 == cutback.den());

    Rational r1 = { 4,8 };
    Rational r2 = { 5,7 };
    Rational r3;
    int i = 10;

    r3 = r1;
    CHECK(r1.num() == r3.num());
    CHECK(r1.den() == r3.den());

    r1 += r2;
    CHECK(17 == r1.num());
    CHECK(14 == r1.den());

    r1 -= r2;
    CHECK(1 == r1.num());
    CHECK(2 == r1.den());

    r1 += i;
    CHECK(21 == r1.num());
    CHECK(2 == r1.den());

    r1 -= i;
    CHECK(1 == r1.num());
    CHECK(2 == r1.den());

    r1 *= r2;
    CHECK(5 == r1.num());
    CHECK(14 == r1.den());

    r1 /= r2;
    CHECK(1 == r1.num());
    CHECK(2 == r1.den());

    r1 *= i;
    CHECK(5 == r1.num());
    CHECK(1 == r1.den());

    r1 /= i;
    CHECK(1 == r1.num());
    CHECK(2 == r1.den());

    Rational r11;

    r11 = r1 + r2;;
    CHECK(17 == r11.num());
    CHECK(14 == r11.den());

    r11 = { 0,1 };
    r11 = r2 - r1;
    CHECK(3 == r11.num());
    CHECK(14 == r11.den());

    r11 = { 0,1 };
    r11 = r1 + i;
    CHECK(21 == r11.num());
    CHECK(2 == r11.den());

    r11 = { 0,1 };
    r11 = i + r1;
    CHECK(21 == r11.num());
    CHECK(2 == r11.den());

    r11 = { 0,1 };
    r11 = r2 - i;
    CHECK(-65 == r11.num());
    CHECK(7 == r11.den());

    r11 = { 0,1 };
    r11 = i - r2;
    CHECK(65 == r11.num());
    CHECK(7 == r11.den());

    r11 = { 0,1 };
    r11 = r2 * r1;
    CHECK(5 == r11.num());
    CHECK(14 == r11.den());

    r11 = { 0,1 };
    r11 = r1 * i;
    CHECK(5 == r11.num());
    CHECK(1 == r11.den());

    r11 = { 0,1 };
    r11 = i * r1;
    CHECK(5 == r11.num());
    CHECK(1 == r11.den());

    r11 = { 0,1 };
    r11 = r1 / r2;
    CHECK(7 == r11.num());
    CHECK(10 == r11.den());

    r11 = { 0,1 };
    r11 = r1 / i;
    CHECK(1 == r11.num());
    CHECK(20 == r11.den());

    r11 = { 0,1 };
    r11 = i / r1;
    CHECK(20 == r11.num());
    CHECK(1 == r11.den());

    CHECK(false == (r1 > r2));
    CHECK(true == (r1 < r2));
    CHECK(false == (r1 >= r2));
    CHECK(true == (r1 <= r2));
    CHECK(false == (r1 == r2));
    CHECK(true == (r1 != r2));

    CHECK(false == (r1 > i));
    CHECK(true == (r1 < i));
    CHECK(false == (r1 >= i));
    CHECK(true == (r1 <= i));
    CHECK(false == (r1 == i));
    CHECK(true == (r1 != i));

    CHECK(true == (i > r1));
    CHECK(false == (i < r1));
    CHECK(true == (i >= r1));
    CHECK(false == (i <= r1));
    CHECK(false == (i == r1));
    CHECK(true == (i != r1));

    CHECK(true == testParse("2/3 "));
    CHECK(true == testParse("2 / 3 "));
    CHECK(false == testParse("2  3"));

    CHECK_THROWS(Rational(1, 0));
}
