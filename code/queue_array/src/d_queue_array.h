#include <memory>

#pragma once
#ifndef DQUEUEARRAY_H
#define DQUEUEARRAY_H

namespace DI 
{
    template<class DataType>
    class DQueueArray
    {
    public:
        DQueueArray(size_t size);
        DQueueArray (const DQueueArray &) = delete;
        DQueueArray &operator=(const DQueueArray &) = delete;

        void Enqueue(DataType value);
        DataType Dequeue();
        bool IsEmpty() const;
        bool IsFull() const;
    private:
        size_t size_ = 5ul;
        size_t index_read_ = 0ul;
        size_t index_write_ = 0ul;
        std::unique_ptr<DataType[]> data_;
    };
}
#endif //DQUEUEARRAY_H


