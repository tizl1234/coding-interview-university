#include "pqueue.h"
#include "pqueue.cpp"

#include <iostream>
int main(int argc, char const *argv[])
{
    DI::PriorityQueue<float> Queue(5);

    Queue.Insert(5, 11.65f);
    Queue.Insert(10, 12.5f);
    Queue.Insert(2, 66.0f);
    Queue.Insert(12, 223.443f);

    std::cout << Queue.IsEmpty() << std::endl;
    std::cout << Queue.ExtractMax()->key << std::endl;
    std::cout << Queue.ExtractMax()->key << std::endl;
    std::cout << Queue.ExtractMax()->key << std::endl;
    std::cout << Queue.ExtractMax()->key << std::endl;
    std::cout << Queue.IsEmpty() << std::endl;

    return EXIT_SUCCESS;
}
