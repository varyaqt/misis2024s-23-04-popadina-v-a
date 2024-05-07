#include "queuearr/queuearr.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("queuearr ctor") {
    Complex c1 = { 1, 0 };
    Complex c2 = { 2, 0 };
    Complex c3 = { 3, 0 };
    QueueArr q1;
    REQUIRE(q1.IsEmpty() == true);
    REQUIRE(q1.Count() == 0);

    q1.Push(c1);
    REQUIRE(q1.IsEmpty() == false);
    REQUIRE(q1.Count() == 1);
    REQUIRE(q1.Top() == c1);

    q1.Push(c2);
    q1.Push(c3);
    REQUIRE(q1.IsEmpty() == false);
    REQUIRE(q1.Count() == 3);
    REQUIRE(q1.Top() == c1);

    QueueArr q2;
    q2.Push(c1);
    q2.Pop();
    REQUIRE(q2.IsEmpty() == true);
    REQUIRE(q2.Count() == 0);
    q2.Push(c1);
    q2.Push(c2);
    q2.Push(c3);
    q2.Pop();
    q2.Pop();
    REQUIRE(q2.IsEmpty() == false);
    REQUIRE(q2.Count() == 1);
    REQUIRE(q2.Top() == c3);

    QueueArr q3;
    q3.Push(c1);
    q3.Push(c2);
    q3.Push(c3);
    q3.Clear();
    REQUIRE(q3.IsEmpty() == true);
    REQUIRE(q3.Count() == 0);

    QueueArr q4(q1);
    REQUIRE(q4.IsEmpty() == false);
    REQUIRE(q4.Count() == 3);
    REQUIRE(q4.Top() == c1);
    q4.Pop();
    REQUIRE(q4.Count() == 2);
    REQUIRE(q4.Top() == c2);
    REQUIRE(q1.Count() == 3);
    REQUIRE(q1.Top() == c1);

    QueueArr q5;
    q5 = q1;
    REQUIRE(q5.IsEmpty() == false);
    REQUIRE(q5.Count() == 3);
    REQUIRE(q5.Top() == c1);
    q5.Pop();
    REQUIRE(q5.Count() == 2);
    REQUIRE(q5.Top() == c2);
    REQUIRE(q1.Count() == 3);
    REQUIRE(q1.Top() == c1);
}
