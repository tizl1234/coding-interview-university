#include <iostream>
#include "d_queue_array.h"

namespace DI
{
    template<class DataType>
    DQueueArray<DataType>::DQueueArray(size_t size) {
        size_ = size;
        data_ = std::unique_ptr<DataType[]>(new DataType[size_]);
    }

    template<class DataType>
    void DQueueArray<DataType>::Enqueue(DataType value) {
        if (IsFull()) {
           std::cerr << "Queue is full" << std::endl;
           exit(EXIT_FAILURE);
        }

        data_[index_write_] = value;

        index_write_ = (index_write_ + 1) % size_;
    }

    template<class DataType>
    DataType DQueueArray<DataType>::Dequeue() {
        if (IsEmpty()) {
            std::cerr << "Queue is empty" << std::endl;
            exit(EXIT_FAILURE);
        }

        DataType result = data_[index_read_];

        index_read_ = (index_read_ + 1) % size_;

        return result;
    }

    template<class DataType>
    bool DQueueArray<DataType>::IsEmpty() const {
        return (index_write_ == index_read_);
    }

    template<class DataType>
    bool DQueueArray<DataType>::IsFull() const {
        return (index_read_ == (index_write_ + 1) % size_);
    }
}
