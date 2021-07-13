#include "pqueue.h"
#include <iostream>
int main(int argc, char const *argv[])
{
    DI::PriorityQueue Queue(5);

    Queue.Insert(5);
    Queue.Insert(10);
    Queue.Insert(2);
    Queue.Insert(12);

    std::cout << Queue.ExtractMax() << std::endl;
    std::cout << Queue.ExtractMax() << std::endl;
    std::cout << Queue.ExtractMax() << std::endl;
    std::cout << Queue.ExtractMax() << std::endl;

    return EXIT_SUCCESS;
}
