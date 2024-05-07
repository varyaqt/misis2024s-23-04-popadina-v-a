#include "queuelstt/queuelstt.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>

TEST_CASE("queuelsttt ctor") {
    float f1 = 1.2, f2 = 3.4, f3 = 5.6;
    QueueLstT<float> qf1;
    REQUIRE(qf1.IsEmpty() == true);

    qf1.Push(f1);
    REQUIRE(qf1.IsEmpty() == false);
    REQUIRE(qf1.Top() == f1);

    qf1.Push(f2);
    qf1.Push(f3);
    REQUIRE(qf1.IsEmpty() == false);
    REQUIRE(qf1.Top() == f1);

    QueueLstT<float> qf2;
    qf2.Push(f1);
    qf2.Pop();
    REQUIRE(qf2.IsEmpty() == true);
    qf2.Push(f1);
    qf2.Push(f2);
    qf2.Push(f3);
    qf2.Pop();
    qf2.Pop();
    REQUIRE(qf2.IsEmpty() == false);
    REQUIRE(qf2.Top() == f3);

    QueueLstT<float> qf3;
    qf3.Push(f1);
    qf3.Push(f2);
    qf3.Push(f3);
    qf3.Clear();
    REQUIRE(qf3.IsEmpty() == true);

    QueueLstT<float> qf4(qf1);
    REQUIRE(qf4.IsEmpty() == false);
    REQUIRE(qf4.Top() == f1);
    qf4.Pop();
    REQUIRE(qf4.Top() == f2);
    REQUIRE(qf1.Top() == f1);

    QueueLstT<float> qf5;
    qf5 = qf1;
    REQUIRE(qf5.IsEmpty() == false);
    REQUIRE(qf5.Top() == f1);
    qf5.Pop();
    REQUIRE(qf5.Top() == f2);
    REQUIRE(qf1.Top() == f1);


    int i1 = 1, i2 = 2, i3 = 3;
    QueueLstT<int> qi1;
    REQUIRE(qi1.IsEmpty() == true);

    qi1.Push(i1);
    REQUIRE(qi1.IsEmpty() == false);
    REQUIRE(qi1.Top() == i1);

    qi1.Push(i2);
    qi1.Push(i3);
    REQUIRE(qi1.IsEmpty() == false);
    REQUIRE(qi1.Top() == i1);

    QueueLstT<int> qi2;
    qi2.Push(i1);
    qi2.Pop();
    REQUIRE(qi2.IsEmpty() == true);
    qi2.Push(i1);
    qi2.Push(i2);
    qi2.Push(i3);
    qi2.Pop();
    qi2.Pop();
    REQUIRE(qi2.IsEmpty() == false);
    REQUIRE(qi2.Top() == i3);

    QueueLstT<int> qi3;
    qi3.Push(i1);
    qi3.Push(i2);
    qi3.Push(i3);
    qi3.Clear();
    REQUIRE(qf3.IsEmpty() == true);

    QueueLstT<int> qi4(qi1);
    REQUIRE(qi4.IsEmpty() == false);
    REQUIRE(qi4.Top() == i1);
    qi4.Pop();
    REQUIRE(qi4.Top() == i2);
    REQUIRE(qi1.Top() == i1);

    QueueLstT<int> qi5;
    qi5 = qi1;
    REQUIRE(qi5.IsEmpty() == false);
    REQUIRE(qi5.Top() == i1);
    qi5.Pop();
    REQUIRE(qi5.Top() == i2);
    REQUIRE(qi1.Top() == i1);


    std::string s1 = "cat", s2 = "mouse", s3 = "book";
    QueueLstT<std::string> qs1;
    REQUIRE(qs1.IsEmpty() == true);

    qs1.Push(s1);
    REQUIRE(qs1.IsEmpty() == false);
    REQUIRE(qs1.Top() == s1);

    qs1.Push(s2);
    qs1.Push(s3);
    REQUIRE(qs1.IsEmpty() == false);
    REQUIRE(qs1.Top() == s1);

    QueueLstT<std::string> qs2;
    qs2.Push(s1);
    qs2.Pop();
    REQUIRE(qs2.IsEmpty() == true);
    qs2.Push(s1);
    qs2.Push(s2);
    qs2.Push(s3);
    qs2.Pop();
    qs2.Pop();
    REQUIRE(qs2.IsEmpty() == false);
    REQUIRE(qs2.Top() == s3);

    QueueLstT<std::string> qs3;
    qs3.Push(s1);
    qs3.Push(s2);
    qs3.Push(s3);
    qs3.Clear();
    REQUIRE(qs3.IsEmpty() == true);

    QueueLstT<std::string> qs4(qs1);
    REQUIRE(qs4.IsEmpty() == false);
    REQUIRE(qs4.Top() == s1);
    qs4.Pop();
    REQUIRE(qs4.Top() == s2);
    REQUIRE(qs1.Top() == s1);

    QueueLstT<std::string> qs5;
    qs5 = qs1;
    REQUIRE(qs5.IsEmpty() == false);
    REQUIRE(qs5.Top() == s1);
    qs5.Pop();
    REQUIRE(qs5.Top() == s2);
    REQUIRE(qs1.Top() == s1);

}

