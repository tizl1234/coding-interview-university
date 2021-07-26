#pragma once

#include <memory>
#include <string>
#include "d_hash_table_object.h"

namespace DI {
    template< class ValueDataType>
    class DHashTable {

    public:
        DHashTable(const size_t size);
        DHashTable(const DHashTable &) = delete;
        DHashTable &operator=(const DHashTable &) = delete;

        void Add(DHashObject<ValueDataType>* object);
        void Remove(const std::string key);
        // bool Exists(const std::string key) const;
        const ValueDataType Get(const std::string key);
        void PrintDebug() const;

    private:
        size_t size_;
        size_t capacity_ = 0ul;
        std::unique_ptr<DHashObject<ValueDataType>[]> data_;

        size_t Hash(const std::string key);
    };
}