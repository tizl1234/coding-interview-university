#include <memory>
#include "pqueue_node.h"
#pragma once
namespace DI {
    template<class DataType>
    class PriorityQueue {
    public:
        PriorityQueue(std::size_t size);
        PriorityQueue(const PriorityQueue &) = delete;
        PriorityQueue &operator=(const PriorityQueue &) = delete;

        bool IsEmpty() const;
        void Insert(size_t key, DataType value);
        DataType GetMax() const { return data_[1].value; }
        PQueueNode<DataType>* ExtractMax();
    private:
        size_t capacity_ = 0; // heap capacity
        size_t size_; // actual array size
        std::unique_ptr<PQueueNode<DataType>[]> data_;

        void SiftUp(size_t index);
        void SiftDown(size_t index);
        size_t Left(size_t index);
        size_t Right(size_t index);
        size_t Parent(size_t index);
       
        void Swap(const size_t A, const size_t B);
        
        //void HeapSort();
    };
}
