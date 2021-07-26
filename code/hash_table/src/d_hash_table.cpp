#include "d_hash_table.h"
#include <iostream>

namespace DI {

    template<class ValueDataType>
    DHashTable<ValueDataType>::DHashTable(const size_t size) {
        size_ = size;
        data_ = std::unique_ptr<DHashObject<ValueDataType>[]>(new DHashObject<ValueDataType>[size_]);

        for (size_t i = 0; i < size_; ++i) {
            data_[i].SetAsNull();
        }
    }

    template<class ValueDataType>
    size_t DHashTable<ValueDataType>::Hash(const std::string Key) {
        size_t hash = 0, a = 127;

        for (const auto& it : Key) { //code from Sedgewick p.535
            hash = (a*hash + it) % size_;
        }
        
        return hash;
    }

    template<class ValueDataType>
    void DHashTable<ValueDataType>::Add(DHashObject<ValueDataType>* object) {
        size_t index = Hash(object->GetKey());
        
        while (!data_[index].IsNull())//trying to find empty place for insertion
        {
           index = (index + 1) % size_;
        }
        
        data_[index].SetKey(object->GetKey());
        data_[index].SetValue(object->GetValue());
        ++capacity_;
    }

    template<class ValueDataType>
    const ValueDataType DHashTable<ValueDataType>::Get(const std::string key) {
        size_t index = Hash(key);

        while (!data_[index].IsNull())
        {
            if (key == data_[index].GetKey()) {
                return data_[index].GetValue();
            } else {
                index = (index + 1) % size_;
            }
        }

        return ValueDataType();
    }

    template<class ValueDataType>
    void DHashTable<ValueDataType>::Remove(std::string key) {
        size_t index = Hash(key);

        while (!data_[index].IsNull())
        {
            if (key == data_[index].GetKey()) {
                data_[index].SetAsNull();
                return;
            } else {
                index = (index + 1) % size_;
            }
        }

        return;
    }

    template<class ValueDataType>
    void DHashTable<ValueDataType>::PrintDebug() const {
        for (size_t i = 0; i < size_; ++i) {
            std::cout << i << ": " << data_[i].GetKey() << ":" << data_[i].GetValue() << std::endl;
        }

        std::cout << "--------------------------\n" << std::endl;
    }

}