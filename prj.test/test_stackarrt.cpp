#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stackarrt/stackarrt.hpp"
#include <cstdint>
#include <string>

TEST_CASE("stackarrt ctor") {
	StackArrT<float> stf1;
    CHECK_EQ(true, stf1.IsEmpty());
    float f1 = 1.2, f2 = 3.4, f3 = 5.6;
    stf1.Push(f1);
    stf1.Push(f2);
    stf1.Push(f3);
    StackArrT<float> stf2 = stf1;
    CHECK_EQ(stf2.IsEmpty(), false);
    CHECK_EQ(stf2.Top(), f3);
    stf2.Pop();
    CHECK_EQ(stf2.Top(), f2);
    stf2.Pop();
    CHECK_EQ(stf2.Top(), f1);
    stf2.Pop();
    CHECK_EQ(stf2.IsEmpty(), true);

    StackArrT<float> stf3 = stf1;
    CHECK_EQ(stf3.IsEmpty(), false);
    CHECK_EQ(stf3.Top(), f3);
    stf3.Pop();
    CHECK_EQ(stf3.Top(), f2);
    stf3.Pop();
    CHECK_EQ(stf3.Top(), f1);
    stf3.Pop();
    CHECK_EQ(stf3.IsEmpty(), true);

    StackArrT<float> stf4;
    stf4.Push(f1);
    stf4.Push(f2);
    stf4.Push(f3);
    CHECK_EQ(stf4.IsEmpty(), false);
    CHECK_EQ(stf4.Top(), f3);
    stf4.Pop();
    CHECK_EQ(stf4.Top(), f2);
    stf4.Pop();
    CHECK_EQ(stf4.Top(), f1);
    stf4.Pop();
    CHECK_EQ(stf4.IsEmpty(), true);

    StackArrT<float> stf5;
    stf5.Push(f1);
    CHECK_EQ(stf5.Top(), f1);
    stf5.Push(f2);
    stf5.Push(f3);
    stf5.Clear();
    CHECK_EQ(stf5.IsEmpty(), true);


	StackArrT<int> sti1;
    CHECK_EQ(true, sti1.IsEmpty());
    int i1 = 1, i2 = 2, i3 = 3;
    sti1.Push(i1);
    sti1.Push(i2);
    sti1.Push(i3);
    StackArrT<int> sti2 = sti1;
    CHECK_EQ(sti2.IsEmpty(), false);
    CHECK_EQ(sti2.Top(), i3);
    sti2.Pop();
    CHECK_EQ(sti2.Top(), i2);
    sti2.Pop();
    CHECK_EQ(sti2.Top(), i1);
    sti2.Pop();
    CHECK_EQ(sti2.IsEmpty(), true);

    StackArrT<int> sti3 = sti1;
    CHECK_EQ(sti3.IsEmpty(), false);
    CHECK_EQ(sti3.Top(), i3);
    sti3.Pop();
    CHECK_EQ(sti3.Top(), i2);
    sti3.Pop();
    CHECK_EQ(sti3.Top(), i1);
    sti3.Pop();
    CHECK_EQ(sti3.IsEmpty(), true);

    StackArrT<int> sti4;
    sti4.Push(i1);
    sti4.Push(i2);
    sti4.Push(i3);
    CHECK_EQ(sti4.IsEmpty(), false);
    CHECK_EQ(sti4.Top(), i3);
    sti4.Pop();
    CHECK_EQ(sti4.Top(), i2);
    sti4.Pop();
    CHECK_EQ(sti4.Top(), i1);
    sti4.Pop();
    CHECK_EQ(sti4.IsEmpty(), true);

    StackArrT<int> sti5;
    sti5.Push(i1);
    CHECK_EQ(sti5.Top(), i1);
    sti5.Push(i2);
    sti5.Push(i3);
    sti5.Clear();
    CHECK_EQ(sti5.IsEmpty(), true);


	StackArrT<std::string> sts1;
    CHECK_EQ(true, sts1.IsEmpty());
    std::string s1 = "cat", s2 = "love", s3 = "disco";
    sts1.Push(s1);
    sts1.Push(s2);
    sts1.Push(s3);
    StackArrT<std::string> sts2 = sts1;
    CHECK_EQ(sts2.IsEmpty(), false);
    CHECK_EQ(sts2.Top(), s3);
    sts2.Pop();
    CHECK_EQ(sts2.Top(), s2);
    sts2.Pop();
    CHECK_EQ(sts2.Top(), s1);
    sts2.Pop();
    CHECK_EQ(sts2.IsEmpty(), true);

    StackArrT<std::string> sts3 = sts1;
    CHECK_EQ(sts3.IsEmpty(), false);
    CHECK_EQ(sts3.Top(), s3);
    sts3.Pop();
    CHECK_EQ(sts3.Top(), s2);
    sts3.Pop();
    CHECK_EQ(sts3.Top(), s1);
    sts3.Pop();
    CHECK_EQ(sts3.IsEmpty(), true);

    StackArrT<std::string> sts4;
    sts4.Push(s1);
    sts4.Push(s2);
    sts4.Push(s3);
    CHECK_EQ(sts4.IsEmpty(), false);
    CHECK_EQ(sts4.Top(), s3);
    sts4.Pop();
    CHECK_EQ(sts4.Top(), s2);
    sts4.Pop();
    CHECK_EQ(sts4.Top(), s1);
    sts4.Pop();
    CHECK_EQ(sts4.IsEmpty(), true);

    StackArrT<std::string> sts5;
    sts5.Push(s1);
    CHECK_EQ(sts5.Top(), s1);
    sts5.Push(s2);
    sts5.Push(s3);
    sts5.Clear();
    CHECK_EQ(sts5.IsEmpty(), true);	
}
