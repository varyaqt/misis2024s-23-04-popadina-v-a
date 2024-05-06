#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <stacklstt/stacklstt.hpp>
#include <string>

TEST_CASE("StackLstT ctor") {
    StackLstT<int> si1;
    REQUIRE(si1.IsEmpty() == true);
    int i1 = 1, i2 = 2, i3 = 3;
    si1.Push(i1);
    si1.Push(i2);
    si1.Push(i3);

    StackLstT<int> si2 = si1;
    REQUIRE(si2.IsEmpty() == false);
    REQUIRE(si2.Top() == i3);
    si2.Pop();
    REQUIRE(si2.Top() == i2);
    si2.Pop();
    REQUIRE(si2.Top() == i1);
    si2.Pop();
    REQUIRE(si2.IsEmpty() == true);

    StackLstT<int> si3;
    si3 = si1;
    REQUIRE(si3.IsEmpty() == false);
    REQUIRE(si3.Top() == i3);
    si3.Pop();
    REQUIRE(si3.Top() == i2);
    si3.Pop();
    REQUIRE(si3.Top() == i1);
    si3.Pop();
    REQUIRE(si3.IsEmpty() == true);

    REQUIRE(si1.Top() == i3);
    si1.Pop();
    REQUIRE(si1.Top() == i2);
    si1.Pop();
    REQUIRE(si1.Top() == i1);
    si1.Pop();
    REQUIRE(si1.IsEmpty() == true);

    StackLstT<int> si4;
    si4.Push(i1);
    REQUIRE(si4.Top() == i1);
    si4.Push(i2);
    si4.Push(i3);
    si4.Clear();
    REQUIRE(si4.IsEmpty() == true);

    StackLstT<float> sf1;
    REQUIRE(sf1.IsEmpty() == true);
    float f1 = 1.2, f2 = 3.4, f3 = 5.6;
    sf1.Push(f1);
    sf1.Push(f2);
    sf1.Push(f3);

    StackLstT<float> sf2 = sf1;
    REQUIRE(sf2.IsEmpty() == false);
    REQUIRE(sf2.Top() == f3);
    sf2.Pop();
    REQUIRE(sf2.Top() == f2);
    sf2.Pop();
    REQUIRE(sf2.Top() == f1);
    sf2.Pop();
    REQUIRE(sf2.IsEmpty() == true);

    StackLstT<float> sf3;
    sf3 = sf1;
    REQUIRE(sf3.IsEmpty() == false);
    REQUIRE(sf3.Top() == f3);
    sf3.Pop();
    REQUIRE(sf3.Top() == f2);
    sf3.Pop();
    REQUIRE(sf3.Top() == f1);
    sf3.Pop();
    REQUIRE(sf3.IsEmpty() == true);

    REQUIRE(sf1.Top() == f3);
    sf1.Pop();
    REQUIRE(sf1.Top() == f2);
    sf1.Pop();
    REQUIRE(sf1.Top() == f1);
    sf1.Pop();
    REQUIRE(sf1.IsEmpty() == true);

    StackLstT<float> sf4;
    sf4.Push(f1);
    REQUIRE(sf4.Top() == f1);
    sf4.Push(f2);
    sf4.Push(f3);
    sf4.Clear();
    REQUIRE(sf4.IsEmpty() == true);

    StackLstT<std::string> ss1;
    REQUIRE(ss1.IsEmpty() == true);
    std::string s1 = "cat", s2 = "ice", s3 = "sea";
    ss1.Push(s1);
    ss1.Push(s2);
    ss1.Push(s3);

    StackLstT<std::string> ss2 = ss1;
    REQUIRE(ss2.IsEmpty() == false);
    REQUIRE(ss2.Top() == s3);
    ss2.Pop();
    REQUIRE(ss2.Top() == s2);
    ss2.Pop();
    REQUIRE(ss2.Top() == s1);
    ss2.Pop();
    REQUIRE(ss2.IsEmpty() == true);

    StackLstT<std::string> ss3;
    ss3 = ss1;
    REQUIRE(ss3.IsEmpty() == false);
    REQUIRE(ss3.Top() == s3);
    ss3.Pop();
    REQUIRE(ss3.Top() == s2);
    ss3.Pop();
    REQUIRE(ss3.Top() == s1);
    ss3.Pop();
    REQUIRE(ss3.IsEmpty() == true);

    REQUIRE(ss1.Top() == s3);
    ss1.Pop();
    REQUIRE(ss1.Top() == s2);
    ss1.Pop();
    REQUIRE(ss1.Top() == s1);
    ss1.Pop();
    REQUIRE(ss1.IsEmpty() == true);

    StackLstT<std::string> ss4;
    ss4.Push(s1);
    REQUIRE(ss4.Top() == s1);
    ss4.Push(s2);
    ss4.Push(s3);
    ss4.Clear();
    REQUIRE(ss4.IsEmpty() == true);

}

