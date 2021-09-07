#include <string>
#ifndef DHASHOBJECT_CPP
#define DHASHOBJECT_CPP

namespace DI {
    template<class ValueDataType>
    class DHashObject {
        public:
            DHashObject(/* args */);
            ~DHashObject();
            DHashObject(const DHashObject &) = delete;
            DHashObject &operator=(const DHashObject &) = default;

            std::string &GetKey();
            ValueDataType &GetValue();

            void SetKey(const std::string key);
            void SetValue(const ValueDataType value);
            bool IsNull() const;
            void SetAsNull() {
                key_ = GetNullkey();
            }
            static const std::string GetNullkey() { return std::string("Null"); }

        private:
            std::string key_;
            ValueDataType value_;
    };

    template<class ValueDataType>
    DHashObject<ValueDataType>::DHashObject(/* args */) {}

    template<class ValueDataType>
    DHashObject<ValueDataType>::~DHashObject() {}

    template<class ValueDataType>
    std::string &DHashObject<ValueDataType>::GetKey (/* args */) {
        return key_;
    }

    template<class ValueDataType>
    ValueDataType &DHashObject<ValueDataType>::GetValue(/* args */) {
        return value_;
    }

    template<class ValueDataType>
    void DHashObject<ValueDataType>::SetKey (const std::string key) {
        key_ = key;
    }

    template<class ValueDataType>
    void DHashObject<ValueDataType>::SetValue (const ValueDataType value) {
        value_ = value;
    }

    template<class ValueDataType>
    bool DHashObject<ValueDataType>::IsNull() const {
        return key_ == GetNullkey();
    }
}
#endif 

