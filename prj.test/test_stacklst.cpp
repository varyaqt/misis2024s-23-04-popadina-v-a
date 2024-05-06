#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <stacklst/stacklst.hpp>

TEST_CASE("stacklst ctor") {
    StackLst stack1;
    REQUIRE(stack1.IsEmpty() == true);
    Complex c1 = { 1, 0 };
    Complex c2 = { 2, 0 };
    Complex c3 = { 3, 0 };
    stack1.Push(c1);
    stack1.Push(c2);
    stack1.Push(c3);

    StackLst stack2 = stack1;
    REQUIRE(stack2.IsEmpty() == false);
    REQUIRE(stack2.Top() == c3);
    stack2.Pop();
    REQUIRE(stack2.Top() == c2);
    stack2.Pop();
    REQUIRE(stack2.Top() == c1);
    stack2.Pop();
    REQUIRE(stack2.IsEmpty() == true);

    StackLst stack3;
    stack3 = stack1;
    REQUIRE(stack3.IsEmpty() == false);
    REQUIRE(stack3.Top() == c3);
    stack3.Pop();
    REQUIRE(stack3.Top() == c2);
    stack3.Pop();
    REQUIRE(stack3.Top() == c1);
    stack3.Pop();
    REQUIRE(stack3.IsEmpty() == true);

    REQUIRE(stack1.Top() == c3);
    stack1.Pop();
    REQUIRE(stack1.Top() == c2);
    stack1.Pop();
    REQUIRE(stack1.Top() == c1);
    stack1.Pop();
    REQUIRE(stack1.IsEmpty() == true);

    StackLst stack4;
    stack4.Push(c1);
    REQUIRE(stack4.Top() == c1);
    stack4.Push(c2);
    stack4.Push(c3);
    stack4.Clear();
    REQUIRE(stack4.IsEmpty() == true);
}
