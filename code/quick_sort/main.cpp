#include <iostream>
#include <stdlib.h>
#include <memory>

void Partition(int* ArrayToSort, size_t ArraySize) {
    if (ArraySize < 2)
    {
        return;
    }
    
    int Pivot = ArrayToSort[rand() % ArraySize];
    size_t FrontSelector = 0;
    size_t BackSelector = ArraySize - 1;

    while (FrontSelector < BackSelector) {
        while (ArrayToSort[FrontSelector] < Pivot) { ++FrontSelector; }
        while (ArrayToSort[BackSelector] > Pivot) { --BackSelector; }

        int tmp = ArrayToSort[FrontSelector];

        ArrayToSort[FrontSelector] = ArrayToSort[BackSelector];
        ArrayToSort[BackSelector] = tmp;
    }

    Partition(ArrayToSort, FrontSelector);
    Partition(&ArrayToSort[FrontSelector + 1], ArraySize - FrontSelector - 1);
}

void QuickSort(int* ArrayToSort, size_t ArraySize) {
    srand((unsigned int)time(0));
    Partition(ArrayToSort, ArraySize);
}

int main(int argc, char const *argv[])
{
    srand (time(NULL));
    size_t size = 12;
    int* array = new int[size];

    for (size_t i = 0; i < size; ++i) {
        array[i] = rand() % 200 + 1;
    }

    QuickSort(array, size);

    for (size_t i = 0; i < size; ++i) {
        std::cout << array[i] << ", ";
    }

    return EXIT_SUCCESS;
}
