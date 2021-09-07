#include "pqueue.h"

namespace DI {
    template <class DataType>
    PriorityQueue<DataType>::PriorityQueue(size_t size) {
        size_ = size + 1;
        data_ = std::unique_ptr<PQueueNode<DataType>[]>(new PQueueNode<DataType>[size]);
        data_[0].key = -1;
    }

    template <class DataType>
    PriorityQueue<DataType>::PriorityQueue(PQueueNode<DataType>* array, size_t size) {
        size_ = size; //assume that 0 elemient is -1
        data_ = std::unique_ptr<PQueueNode<DataType>[]>(array);
        capacity_ = size - 1;
        BuildMaxHeap();
    }

    template <class DataType>
    bool PriorityQueue<DataType>::IsEmpty() const {
        return capacity_ == 0;
    }

    template <class DataType>
    void PriorityQueue<DataType>::SiftDown(size_t index) {
        if (index > capacity_) return;

        size_t l = Left(index);
        size_t r = Right(index);
        size_t SwapIndex = index;

        if (l <= capacity_ && data_[l].key > data_[index].key) { // left child exists and it's bigger than parent
            SwapIndex = l;
        }

        if (r <= capacity_ && data_[r].key > data_[SwapIndex].key) {  // right child exists and it's bigger than parent
            SwapIndex = r;
        }
        
        if (SwapIndex != index) {
            Swap(index, SwapIndex);
            SiftDown(SwapIndex);
        }

        return;
    }

    template <class DataType>
    void PriorityQueue<DataType>::Insert(size_t key, DataType value) {
        if (capacity_ + 1 < size_) {
            ++capacity_;
            data_[capacity_].key = key;
            data_[capacity_].value = value;
            SiftUp(capacity_);
        }
        //TODO exception throw
        return;
    }

    template <class DataType>
    PQueueNode<DataType>* PriorityQueue<DataType>::ExtractMax() {
        //TODO assert capacity > 0
        PQueueNode<DataType>* MaxValue = new PQueueNode<DataType>(data_[1].key, data_[1].value);

        Swap(1, capacity_--);
        SiftDown(1);
        return MaxValue;
    }

    template <class DataType>
    void PriorityQueue<DataType>::BuildMaxHeap() {
        for (size_t i = capacity_; i >= 1; --i) {
            SiftDown(i);
        }
    }

    template <class DataType>
    size_t PriorityQueue<DataType>::Left(size_t index) {
        return index << 1; // 2 * index;
    }
    template <class DataType>
    size_t PriorityQueue<DataType>::Right(size_t index) {
        return (index << 1) + 1; // 2 * index + 1;
    }

    template <class DataType>
    size_t PriorityQueue<DataType>::Parent(size_t index) {
        return index >> 1; // index / 2;
    }

    template <class DataType>
    void PriorityQueue<DataType>::SiftUp(size_t index) {
        if (index > capacity_) return; // stop sift if index doesn't exist or it's the top of the heap. so end recursion
        if (index == 1) return;
        
        auto parent = Parent(index);

        if (data_[index].key > data_[parent].key) {
            Swap(parent, index);
        }

        SiftUp(parent);
    }

    template <class DataType>
    void PriorityQueue<DataType>::Swap(const size_t A, const size_t B) {
        size_t temp_key = data_[A].key;
        DataType temp_value = data_[A].value;

        data_[A].key = data_[B].key;
        data_[A].value = data_[B].value;

        data_[B].key = temp_key;
        data_[B].value = temp_value;
    }
}