#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "queuelst/queuelst.hpp"

TEST_CASE("queuelst ctor") {
    Complex c1(2, 0);
    Complex c2(3, 4);
    Complex c3(5, 6);
    Complex c4(7, 8);

    QueueLst queue;
    QueueLst queue4;

    queue4.Push(c4);
    CHECK_EQ(0, queue4.IsEmpty());
    CHECK_EQ(c4, queue4.Top());

    CHECK_EQ(1, queue.IsEmpty());
    queue.Pop();
    CHECK_EQ(1, queue.IsEmpty());

    queue.Push(c1);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    queue.Push(c2);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    queue.Push(c3);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    queue.Push(c4);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    QueueLst copu_queue_1(queue);
    QueueLst queue2 = queue;

    queue.Pop();
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c2, queue.Top());

    queue.Pop();
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c3, queue.Top());

    queue.Pop();
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c4, queue.Top());

    queue.Pop();
    CHECK_EQ(1, queue.IsEmpty());

    queue.Push(c1);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    queue.Push(c2);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    queue.Clear();
    CHECK_EQ(1, queue.IsEmpty());

    QueueLst copu_queue_2(queue);
    QueueLst queue3 = queue;

    queue.Push(c1);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    queue.Push(c2);
    CHECK_EQ(0, queue.IsEmpty());
    CHECK_EQ(c1, queue.Top());

    CHECK_EQ(1, queue3.IsEmpty());
    queue3.Pop();
    CHECK_EQ(1, queue3.IsEmpty());

    queue3.Push(c1);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Push(c2);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Push(c3);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Push(c4);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Pop();
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c2, queue3.Top());

    queue3.Pop();
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c3, queue3.Top());

    queue3.Pop();
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c4, queue3.Top());

    queue3.Pop();
    CHECK_EQ(1, queue3.IsEmpty());

    queue3.Push(c1);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Push(c2);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Clear();
    CHECK_EQ(1, queue3.IsEmpty());

    queue3.Push(c1);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());

    queue3.Push(c2);
    CHECK_EQ(0, queue3.IsEmpty());
    CHECK_EQ(c1, queue3.Top());
}
