#include <stackarrt/stackarrt.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <cstdint>
#include <string>

TEST_CASE("[stackarrt] - ctor") {
	StackArrT<float> stf;
	StackArrT<int> sti;
	StackArrT<std::string> sts;
}
