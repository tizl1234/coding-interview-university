#pragma once
namespace DI {
    template <class DataType>
    struct PQueueNode
    {
        size_t key;
        DataType value;
    };
}

