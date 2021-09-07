#include "pqueue.h"
#include "pqueue.cpp"
#include "pqueue_node.h"

#include <iostream>
int main(int argc, char const *argv[])
{
    DI::PriorityQueue<float> Queue(5);

    Queue.Insert(5, 11.65f);
    Queue.Insert(10, 12.5f);
    Queue.Insert(2, 66.0f);
    Queue.Insert(12, 223.443f);

    std::cout << Queue.IsEmpty() << std::endl;
    std::cout << Queue.ExtractMax()->key << ", ";
    std::cout << Queue.ExtractMax()->key << ", ";
    std::cout << Queue.ExtractMax()->key << ", ";
    std::cout << Queue.ExtractMax()->key << std::endl;
    std::cout << Queue.IsEmpty() << std::endl;

    size_t UnsortedSize = 6;
    DI::PQueueNode<float>* UnsortedArray = new DI::PQueueNode<float>[UnsortedSize] {
        DI::PQueueNode<float>(-1, 1),
        DI::PQueueNode<float>(5, 11.65f),
        DI::PQueueNode<float>(10, 12.5f),
        DI::PQueueNode<float>(2, 66.0f),
        DI::PQueueNode<float>(12, 223.443f),
        DI::PQueueNode<float>(88, 1.5f)
    };

    DI::PriorityQueue<float> QueueToSort(UnsortedArray, UnsortedSize);

    std::cout << QueueToSort.IsEmpty() << std::endl;
    std::cout << QueueToSort.ExtractMax()->key << ", ";
    std::cout << QueueToSort.ExtractMax()->key << ", ";
    std::cout << QueueToSort.ExtractMax()->key << ", ";
    std::cout << QueueToSort.ExtractMax()->key << ", ";
    std::cout << QueueToSort.ExtractMax()->key << std::endl;
    std::cout << QueueToSort.IsEmpty() << std::endl;
    return EXIT_SUCCESS;
}
