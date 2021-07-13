#include "pqueue.h"

namespace DI {
    PriorityQueue::PriorityQueue(size_t size) {
        size_ = size + 1;
        data_ = std::unique_ptr<std::int64_t[]>(new std::int64_t[size]);
        data_[0] = -1;
    }

    bool PriorityQueue::IsEmpty() const {
        return capacity_ == 0;
    }

    void PriorityQueue::MaxHeapify(size_t index) {
        if (index > capacity_) return;

        size_t l = Left(index);
        size_t r = Right(index);
        size_t SwapIndex = index;

        if (l <= capacity_ && data_[l] > data_[index]) { // left child exists and it's bigger than parent
            SwapIndex = l;
        }

        if (r <= capacity_ && data_[r] > data_[SwapIndex]) {  // right child exists and it's bigger than parent
            SwapIndex = r;
        }
        
        if (SwapIndex != index) {
            Swap(index, SwapIndex);
            MaxHeapify(SwapIndex);
        }

        return;
    }

    void PriorityQueue::Insert(std::int64_t value) {
        if (capacity_ + 1 < size_) {
            ++capacity_;
            data_[capacity_] = value;
            ShiftUp(capacity_);
        }
        //TODO exception throw
        return;
    }

    std::int64_t PriorityQueue::ExtractMax() {
        auto MaxValue = data_[1];

        Swap(1, capacity_--);
        MaxHeapify(1);
        return MaxValue;
    }

    size_t PriorityQueue::Left(size_t index) {
        return index << 1; // 2 * index;
    }

    size_t PriorityQueue::Right(size_t index) {
        return (index << 1) + 1; // 2 * index + 1;
    }

    size_t PriorityQueue::Parent(size_t index) {
        return index >> 1; // index / 2;
    }

    void PriorityQueue::ShiftUp(size_t index) {
        if (index > capacity_) return; // stop shift if index doesn't exist or it's the top of the heap. so end recursion
        if (index == 1) return;
        
        auto parent = Parent(index);

        if (data_[index] > data_[parent]) {
            Swap(parent, index);
        }

        ShiftUp(parent);
    }

    void PriorityQueue::Swap(const size_t A, const size_t B) {
        auto temp_value = data_[A];

        data_[A] = data_[B];
        data_[B] = temp_value;
    }
}