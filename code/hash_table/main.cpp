#include "src/d_hash_table.h"
#include "src/d_hash_table.cpp"
#include "src/d_hash_table_object.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    DI::DHashTable<int> HashTable(4);

    HashTable.PrintDebug();

    DI::DHashObject<int> Object1;
    Object1.SetKey("First key");
    Object1.SetValue(1);

    DI::DHashObject<int> Object2;
    Object2.SetKey("Second key");
    Object2.SetValue(2);

    DI::DHashObject<int> Object3;
    Object3.SetKey("Third key");
    Object3.SetValue(3);

    DI::DHashObject<int> Object4;
    Object4.SetKey("Fourth key");
    Object4.SetValue(4);

    HashTable.Add(&Object1);
    HashTable.Add(&Object2);
    HashTable.Add(&Object3);
    HashTable.Add(&Object4);

    HashTable.PrintDebug();

    HashTable.Remove("First key");

    HashTable.PrintDebug();
    //const std::string Key("Second key");
    std::cout << HashTable.Get("Second key") << std::endl;
    return EXIT_SUCCESS;
}
