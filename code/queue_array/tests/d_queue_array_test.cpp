#include <iostream>
#include <gtest/gtest.h>
#include "d_queue_array.cpp"
#include "d_queue_array.h"

namespace {
    class EnqueueDequeueTest: public ::testing::Test {};

    TEST_F(EnqueueDequeueTest, TestEnqueueDequeue) {
        DI::DQueueArray<int> Queue(5);

        for (int i = 1; i <= 5; ++i) {
            Queue.Enqueue(i);
        }

        EXPECT_FALSE(Queue.IsEmpty());
        EXPECT_TRUE(Queue.IsFull());

        EXPECT_EQ(Queue.Dequeue(), 1);
        EXPECT_FALSE(Queue.IsFull());

        Queue.Enqueue(6);
        EXPECT_FALSE(Queue.IsEmpty());
        EXPECT_TRUE(Queue.IsFull());

        EXPECT_EQ(Queue.Dequeue(), 2);
        EXPECT_EQ(Queue.Dequeue(), 3);
        EXPECT_EQ(Queue.Dequeue(), 4);
        EXPECT_EQ(Queue.Dequeue(), 5);
        EXPECT_EQ(Queue.Dequeue(), 6);
        EXPECT_TRUE(Queue.IsEmpty());
    }
}