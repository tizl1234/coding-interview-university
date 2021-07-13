#include <memory>

namespace DI {
    class PriorityQueue {
    public:
        PriorityQueue(std::size_t size);
        PriorityQueue(const PriorityQueue &) = delete;
        PriorityQueue &operator=(const PriorityQueue &) = delete;

        bool IsEmpty() const;
        void Insert(std::int64_t value);
        std::int64_t GetMax() const { return data_[1]; }
        std::int64_t ExtractMax();
    private:
        size_t capacity_ = 0; // heap capacity
        size_t size_; // actual array size
        std::unique_ptr<std::int64_t[]> data_;

        void MaxHeapify(size_t index);
        size_t Left(size_t index);
        size_t Right(size_t index);
        size_t Parent(size_t index);
        void ShiftUp(size_t index);
        void Swap(const size_t A, const size_t B);
        
        //void HeapSort();
    };
}
