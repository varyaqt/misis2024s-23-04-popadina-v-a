#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stackarrt/stackarrt.hpp"
#include <cstdint>
#include <string>
#include <vector>

TEST_CASE("stackarrt ctor") {
	StackArrT<float> stf;
	StackArrT<int> sti;
	StackArrT<std::string> sts;
    CHECK_EQ(1, stf.IsEmpty());
    CHECK_EQ(1, sti.IsEmpty());
    CHECK_EQ(1, sts.IsEmpty());
	/*stf(4);
	sti(4);
	sts(4);
	for (int i = 0; i < 4; i++) {
		CHECK_EQ(T{}, stf[i]);
		CHECK_EQ(T{}, sti[i]);
		CHECK_EQ(T{}, sts[i]);
	}*/
	for (int i = 0; i < 100; i++) {
		sti.Push(i);
		CHECK_EQ(i, sti.Top());
	}
	for (int i = 0; i < 100; i++) {
		stf.Push(i + 0.5);
		CHECK_EQ(i + 0.5, sti.Top());
	}
	std::vector<std::string> tes = { "at", "st", "ds", "f", "fg", "h", "t", "a", "s", "fd", "f", "g", "h", "t", "sssssa", "s", "d", "f", "g", "h", "t" };
	for (auto c : tes) {
		sts.Push(c);
		CHECK_EQ(c, sts.Top());
	}
	stf.Clear();
	sti.Clear();
	sts.Clear();
	CHECK_EQ(1, stf.IsEmpty());
	CHECK_EQ(1, sti.IsEmpty());
	CHECK_EQ(1, sts.IsEmpty());

	sti.Push(1);
	sti.Push(2);
	sti.Pop();
	CHECK_EQ(1, sti.Top());

	stf.Push(1.4);
	stf.Push(2.7);
	stf.Pop();
	CHECK_EQ(1.4, sti.Top());

	sts.Push("a");
	sts.Push("b");
	sts.Pop();
	CHECK_EQ("a", sts.Top());
}
