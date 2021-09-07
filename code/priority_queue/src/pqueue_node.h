#pragma once
namespace DI {
    template <class DataType>
    struct PQueueNode
    {
        PQueueNode() {}
        PQueueNode(size_t key, DataType value) : key(key), value(value) {}
        size_t key;
        DataType value;
    };
}

