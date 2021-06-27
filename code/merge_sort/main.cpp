#include <iostream>
#include <stdlib.h>
#include <memory>

void Merge(std::int64_t* array_to_merge, size_t left, size_t middle, size_t right);

void MergeSort(std::int64_t* array_to_sort, size_t left, size_t right);

int main () {
    srand (time(NULL));
    size_t size = 10;
     std::int64_t* array = new std::int64_t[size];

    for (size_t i = 0; i < size; ++i) {
        array[i] = rand() % 200 + 1;
    }

    MergeSort(array, 0, size - 1);

    for (size_t i = 0; i < size; ++i) {
        std::cout << array[i] << ", ";
    }

    return EXIT_SUCCESS;
}

void Merge(std::int64_t* array_to_merge, size_t left, size_t middle, size_t right) {
    size_t i = left;
    size_t j = middle + 1; //midpoint
    size_t k = left;
    auto temp = std::unique_ptr<std::int64_t[]>(new std::int64_t[left + right]);
    
    // compare and put smaller value in temp[]
    while (i <= middle && j <= right) {
        if (array_to_merge[i] <= array_to_merge[j]) {
            temp[k] = array_to_merge[i];
            ++i; ++k;
        } else {
            temp[k] = array_to_merge[j];
            ++j; ++k;
        }
    }

    while (i <= middle) { // copying all elements from left subarray as it is
        temp[k] = array_to_merge[i];
        ++i; ++k;
    }

    while (j <= right) { // copying all elements from right subarray as it is
        temp[k] = array_to_merge[j];
        ++j; ++k;
    }

    // copying elements to original array
    for (size_t p = left; p <= right; ++p) {
        array_to_merge[p] = temp[p];
    }
}

void MergeSort(std::int64_t* array_to_sort, size_t left, size_t right) {
    if (left < right) {
        std::size_t const middle = (left + right) / 2;

        MergeSort(array_to_sort, left, middle);
        MergeSort(array_to_sort, middle + 1, right);

        Merge(array_to_sort, left, middle, right);
    }
}