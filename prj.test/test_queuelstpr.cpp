#include "queuelstpr/queuelstpr.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("QueueLstPr ctor") {
    float f1 = 1.2;
    float f2 = 3.4;
    float f3 = 5.6;
    float f4 = 7.8;
    QueueLstPr q1;
    REQUIRE(q1.IsEmpty() == true);

    q1.Push(f1);
    REQUIRE(q1.IsEmpty() == false);
    REQUIRE(q1.Top() == f1);

    q1.Push(f3);
    q1.Push(f2);
    REQUIRE(q1.IsEmpty() == false);
    REQUIRE(q1.Top() == f1);

    QueueLstPr q2;
    q2.Push(f1);
    q2.Pop();
    REQUIRE(q2.IsEmpty() == true);

    q1.Pop();
    REQUIRE(q1.Top() == f2);

    q1.Clear();
    REQUIRE(q1.IsEmpty() == true);

    q1.Push(f1);
    REQUIRE(q1.Top() == f1);
    q1.Push(f2);
    REQUIRE(q1.Top() == f1);
    q1.Push(f3);
    REQUIRE(q1.Top() == f1);
    q1.Push(f4);
    REQUIRE(q1.Top() == f1);
    REQUIRE(q1.IsEmpty() == false);
    q1.Clear();
    REQUIRE(q1.IsEmpty() == true);

    q1.Push(f4);
    REQUIRE(q1.Top() == f4);
    q1.Push(f3);
    REQUIRE(q1.Top() == f3);
    q1.Push(f2);
    REQUIRE(q1.Top() == f2);
    q1.Push(f1);
    REQUIRE(q1.Top() == f1);

    q1.Pop();
    REQUIRE(q1.Top() == f2);
    q1.Pop();
    REQUIRE(q1.Top() == f3);
    q1.Pop();
    REQUIRE(q1.Top() == f4);
    q1.Pop();
    REQUIRE(q1.IsEmpty() == true);

    q1.Push(f2);
    REQUIRE(q1.Top() == f2);
    q1.Push(f1);
    REQUIRE(q1.Top() == f1);
    q1.Push(f3);
    REQUIRE(q1.Top() == f1);
    q1.Push(f4);
    REQUIRE(q1.Top() == f1);
}
