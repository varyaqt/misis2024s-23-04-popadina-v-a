#include "stackarr/stackarr.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("stackarr ctor") {
    StackArr s1;
    CHECK_EQ(true, s1.IsEmpty());
    Complex c1 = { 1, 0 };
    Complex c2 = { 2, 0 };
    Complex c3 = { 3, 0 };
    s1.Push(c1);
    s1.Push(c2);
    s1.Push(c3);

    StackArr s2 = s1;
    CHECK_EQ(s2.IsEmpty(), false);
    CHECK_EQ(s2.Top(), c3);
    s2.Pop();
    CHECK_EQ(s2.Top(), c2);
    s2.Pop();
    CHECK_EQ(s2.Top(), c1);
    s2.Pop();
    CHECK_EQ(s2.IsEmpty(), true);

    StackArr s3 = s1;
    CHECK_EQ(s3.IsEmpty(), false);
    CHECK_EQ(s3.Top(), c3);
    s3.Pop();
    CHECK_EQ(s3.Top(), c2);
    s3.Pop();
    CHECK_EQ(s3.Top(), c1);
    s3.Pop();
    CHECK_EQ(s3.IsEmpty(), true);

    StackArr s4;
    s4.Push(c1);
    s4.Push(c2);
    s4.Push(c3);
    CHECK_EQ(s4.IsEmpty(), false);
    CHECK_EQ(s4.Top(), c3);
    s4.Pop();
    CHECK_EQ(s4.Top(), c2);
    s4.Pop();
    CHECK_EQ(s4.Top(), c1);
    s4.Pop();
    CHECK_EQ(s4.IsEmpty(), true);

    StackArr s5;
    s5.Push(c1);
    CHECK_EQ(s5.Top(), c1);
    s5.Push(c2);
    s5.Push(c3);
    s5.Clear();
    CHECK_EQ(s5.IsEmpty(), true);
}

