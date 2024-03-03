#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <stacklst/stacklst.hpp>

TEST_CASE("stacklst ctor") {
    Complex c1(2, 0);
    Complex c2(3, 4);
    Complex c3(5, 6);
    Complex c4(7, 8);

    StackLst stack;
    StackLst stack4;

    stack4.Push(c4);
    CHECK_EQ(0, stack4.IsEmpty());
    CHECK_EQ(c4, stack4.Top());

    CHECK_EQ(1, stack.IsEmpty());
    CHECK_THROWS(stack.Top());
    stack.Pop();
    CHECK_EQ(1, stack.IsEmpty());

    stack.Push(c1);
    CHECK_EQ(0, stack.IsEmpty());
    CHECK_EQ(c1, stack.Top());

    stack4 = stack;
    CHECK_EQ(0, stack4.IsEmpty());
    CHECK_EQ(c1, stack4.Top());

    stack.Push(c2);
    CHECK_EQ(0, stack.IsEmpty());
    CHECK_EQ(c2, stack.Top());

    stack4 = stack;
    CHECK_EQ(0, stack4.IsEmpty());
    CHECK_EQ(c2, stack4.Top());

    stack4.Pop();
    CHECK_EQ(0, stack4.IsEmpty());
    CHECK_EQ(c1, stack4.Top());

    stack.Push(c3);
    CHECK_EQ(0, stack.IsEmpty());
    CHECK_EQ(c3, stack.Top());

    stack.Push(c4);
    CHECK_EQ(0, stack.IsEmpty());
    CHECK_EQ(c4, stack.Top());

    StackLst copy_stack_1(stack);
    StackLst stack2 = stack;
    stack4 = stack;

    stack.Pop();
    CHECK_EQ(0, stack.IsEmpty());
    CHECK_EQ(c3, stack.Top());

    stack.Pop();
    CHECK_EQ(0, stack.IsEmpty());
    CHECK_EQ(c2, stack.Top());

    stack.Pop();
    CHECK_EQ(0, stack.IsEmpty());
    CHECK_EQ(c1, stack.Top());

    stack.Pop();
    CHECK_EQ(1, stack.IsEmpty());
    CHECK_THROWS(stack.Top());

    stack.Push(c1);
    CHECK_EQ(0, stack.IsEmpty());
    CHECK_EQ(c1, stack.Top());

    stack.Push(c2);
    CHECK_EQ(0, stack.IsEmpty());
    CHECK_EQ(c2, stack.Top());

    stack.Clear();
    CHECK_EQ(1, stack.IsEmpty());
    CHECK_THROWS(stack.Top());

    StackLst copy_stack_2(stack);
    StackLst stack3 = stack;

    stack.Push(c1);
    CHECK_EQ(0, stack.IsEmpty());
    CHECK_EQ(c1, stack.Top());

    stack.Push(c2);
    CHECK_EQ(0, stack.IsEmpty());
    CHECK_EQ(c2, stack.Top());
    

    SUBCASE("copy_stack_1") {
        CHECK_EQ(0, copy_stack_1.IsEmpty());
        CHECK_EQ(c4, copy_stack_1.Top());

        copy_stack_1.Pop();
        CHECK_EQ(0, copy_stack_1.IsEmpty());
        CHECK_EQ(c3, copy_stack_1.Top());

        copy_stack_1.Pop();
        CHECK_EQ(0, copy_stack_1.IsEmpty());
        CHECK_EQ(c2, copy_stack_1.Top());

        copy_stack_1.Pop();
        CHECK_EQ(0, copy_stack_1.IsEmpty());
        CHECK_EQ(c1, copy_stack_1.Top());

        copy_stack_1.Pop();
        CHECK_EQ(1, copy_stack_1.IsEmpty());
        CHECK_THROWS(copy_stack_1.Top());

        copy_stack_1.Push(c1);
        CHECK_EQ(0, copy_stack_1.IsEmpty());
        CHECK_EQ(c1, copy_stack_1.Top());

        copy_stack_1.Push(c2);
        CHECK_EQ(0, copy_stack_1.IsEmpty());
        CHECK_EQ(c2, copy_stack_1.Top());

        copy_stack_1.Clear();
        CHECK_EQ(1, copy_stack_1.IsEmpty());
        CHECK_THROWS(copy_stack_1.Top());

        copy_stack_1.Push(c1);
        CHECK_EQ(0, copy_stack_1.IsEmpty());
        CHECK_EQ(c1, copy_stack_1.Top());

        copy_stack_1.Push(c2);
        CHECK_EQ(0, copy_stack_1.IsEmpty());
        CHECK_EQ(c2, copy_stack_1.Top());
    }

    SUBCASE("copy_stack_2") {
        CHECK_EQ(1, copy_stack_2.IsEmpty());
        CHECK_THROWS(copy_stack_2.Top());
        copy_stack_2.Pop();
        CHECK_EQ(1, copy_stack_2.IsEmpty());

        copy_stack_2.Push(c1);
        CHECK_EQ(0, copy_stack_2.IsEmpty());
        CHECK_EQ(c1, copy_stack_2.Top());

        copy_stack_2.Push(c2);
        CHECK_EQ(0, copy_stack_2.IsEmpty());
        CHECK_EQ(c2, copy_stack_2.Top());

        copy_stack_2.Push(c3);
        CHECK_EQ(0, copy_stack_2.IsEmpty());
        CHECK_EQ(c3, copy_stack_2.Top());

        copy_stack_2.Push(c4);
        CHECK_EQ(0, copy_stack_2.IsEmpty());
        CHECK_EQ(c4, copy_stack_2.Top());

        copy_stack_2.Pop();
        CHECK_EQ(0, copy_stack_2.IsEmpty());
        CHECK_EQ(c3, copy_stack_2.Top());

        copy_stack_2.Pop();
        CHECK_EQ(0, copy_stack_2.IsEmpty());
        CHECK_EQ(c2, copy_stack_2.Top());

        copy_stack_2.Pop();
        CHECK_EQ(0, copy_stack_2.IsEmpty());
        CHECK_EQ(c1, copy_stack_2.Top());

        copy_stack_2.Pop();
        CHECK_EQ(1, copy_stack_2.IsEmpty());
        CHECK_THROWS(copy_stack_2.Top());

        copy_stack_2.Push(c1);
        CHECK_EQ(0, copy_stack_2.IsEmpty());
        CHECK_EQ(c1, copy_stack_2.Top());

        copy_stack_2.Push(c2);
        CHECK_EQ(0, copy_stack_2.IsEmpty());
        CHECK_EQ(c2, copy_stack_2.Top());

        copy_stack_2.Clear();
        CHECK_EQ(1, copy_stack_2.IsEmpty());
        CHECK_THROWS(copy_stack_2.Top());

        copy_stack_2.Push(c1);
        CHECK_EQ(0, copy_stack_2.IsEmpty());
        CHECK_EQ(c1, copy_stack_2.Top());

        copy_stack_2.Push(c2);
        CHECK_EQ(0, copy_stack_2.IsEmpty());
        CHECK_EQ(c2, copy_stack_2.Top());
    }

    SUBCASE("stack2") {
        CHECK_EQ(0, stack2.IsEmpty());
        CHECK_EQ(c4, stack2.Top());

        stack2.Pop();
        CHECK_EQ(0, stack2.IsEmpty());
        CHECK_EQ(c3, stack2.Top());

        stack2.Pop();
        CHECK_EQ(0, stack2.IsEmpty());
        CHECK_EQ(c2, stack2.Top());

        stack2.Pop();
        CHECK_EQ(0, stack2.IsEmpty());
        CHECK_EQ(c1, stack2.Top());

        stack2.Pop();
        CHECK_EQ(1, stack2.IsEmpty());
        CHECK_THROWS(stack2.Top());

        stack2.Push(c1);
        CHECK_EQ(0, stack2.IsEmpty());
        CHECK_EQ(c1, stack2.Top());

        stack2.Push(c2);
        CHECK_EQ(0, stack2.IsEmpty());
        CHECK_EQ(c2, stack2.Top());

        stack2.Clear();
        CHECK_EQ(1, stack2.IsEmpty());
        CHECK_THROWS(stack2.Top());

        stack2.Push(c1);
        CHECK_EQ(0, stack2.IsEmpty());
        CHECK_EQ(c1, stack2.Top());

        stack2.Push(c2);
        CHECK_EQ(0, stack2.IsEmpty());
        CHECK_EQ(c2, stack2.Top());
    }

    CHECK_EQ(1, stack3.IsEmpty());
    CHECK_THROWS(stack3.Top());
    stack3.Pop();
    CHECK_EQ(1, stack3.IsEmpty());

    stack3.Push(c1);
    CHECK_EQ(0, stack3.IsEmpty());
    CHECK_EQ(c1, stack3.Top());

    stack3.Push(c2);
    CHECK_EQ(0, stack3.IsEmpty());
    CHECK_EQ(c2, stack3.Top());

    stack3.Push(c3);
    CHECK_EQ(0, stack3.IsEmpty());
    CHECK_EQ(c3, stack3.Top());

    stack3.Push(c4);
    CHECK_EQ(0, stack3.IsEmpty());
    CHECK_EQ(c4, stack3.Top());

    stack3.Pop();
    CHECK_EQ(0, stack3.IsEmpty());
    CHECK_EQ(c3, stack3.Top());

    stack3.Pop();
    CHECK_EQ(0, stack3.IsEmpty());
    CHECK_EQ(c2, stack3.Top());

    stack3.Pop();
    CHECK_EQ(0, stack3.IsEmpty());
    CHECK_EQ(c1, stack3.Top());

    stack3.Pop();
    CHECK_EQ(1, stack3.IsEmpty());
    CHECK_THROWS(stack3.Top());

    stack3.Push(c1);
    CHECK_EQ(0, stack3.IsEmpty());
    CHECK_EQ(c1, stack3.Top());

    stack3.Push(c2);
    CHECK_EQ(0, stack3.IsEmpty());
    CHECK_EQ(c2, stack3.Top());

    stack3.Clear();
    CHECK_EQ(1, stack3.IsEmpty());
    CHECK_THROWS(stack3.Top());

    stack3.Push(c1);
    CHECK_EQ(0, stack3.IsEmpty());
    CHECK_EQ(c1, stack3.Top());

    stack3.Push(c2);
    CHECK_EQ(0, stack3.IsEmpty());
    CHECK_EQ(c2, stack3.Top());
    
    CHECK_EQ(0, stack4.IsEmpty());
    CHECK_EQ(c4, stack4.Top());

    stack4.Pop();
    CHECK_EQ(0, stack4.IsEmpty());
    CHECK_EQ(c3, stack4.Top());

    stack4.Pop();
    CHECK_EQ(0, stack4.IsEmpty());
    CHECK_EQ(c2, stack4.Top());

    stack4.Pop();
    CHECK_EQ(0, stack4.IsEmpty());
    CHECK_EQ(c1, stack4.Top());

    stack4.Pop();
    CHECK_EQ(1, stack4.IsEmpty());
    CHECK_THROWS(stack4.Top());

    stack4.Push(c1);
    CHECK_EQ(0, stack4.IsEmpty());
    CHECK_EQ(c1, stack4.Top());

    stack4.Push(c2);
    CHECK_EQ(0, stack4.IsEmpty());
    CHECK_EQ(c2, stack4.Top());

    stack4.Clear();
    CHECK_EQ(1, stack4.IsEmpty());
    CHECK_THROWS(stack4.Top());

    stack4.Push(c1);
    CHECK_EQ(0, stack4.IsEmpty());
    CHECK_EQ(c1, stack4.Top());

    stack4.Push(c2);
    CHECK_EQ(0, stack4.IsEmpty());
    CHECK_EQ(c2, stack4.Top());

    stack4.Push(c3);
    stack4.Push(c4);
    CHECK_EQ(0, stack4.IsEmpty());
    CHECK_EQ(c4, stack4.Top());

    stack4 = stack3;
    CHECK_EQ(0, stack4.IsEmpty());
    CHECK_EQ(c2, stack4.Top());

    stack4.Pop();
    CHECK_EQ(0, stack4.IsEmpty());
    CHECK_EQ(c1, stack4.Top());
    
}
