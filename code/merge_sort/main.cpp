#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <vector>

std::vector<std::int64_t> Merge(std::vector<std::int64_t> array_a, std::vector<std::int64_t> array_b);

std::vector<std::int64_t> MergeSort(std::vector<std::int64_t> array_to_sort);

int main () {
    srand (time(NULL));
    size_t size = 10;
    std::vector<std::int64_t> array(size, 0);

    for (auto &value: array) {
        value = rand() % 200 + 1;
    }

    auto sorted = MergeSort(array);

    for (const auto &value: sorted) {
        std::cout << value << ", ";
    }

    return EXIT_SUCCESS;
}

std::vector<std::int64_t> Merge(std::vector<std::int64_t>array_a, std::vector<std::int64_t> array_b) {
    std::vector<std::int64_t> result_array;

    //this loop smelly as shit
    while (!array_a.empty() && !array_b.empty()) {
        if (array_a.front() > array_b.front()) {
            result_array.push_back(array_b.front());
            array_b.erase(array_b.begin());
        } else {
            result_array.push_back(array_a.front());
            array_a.erase(array_a.begin());
        }
    }

    while (!array_a.empty()) {
        result_array.push_back(array_a.front());
        array_a.erase(array_a.begin());
    }

    while (!array_b.empty()) {
        result_array.push_back(array_b.front());
        array_b.erase(array_b.begin());
    }

    return result_array;
}

std::vector<std::int64_t> MergeSort(std::vector<std::int64_t> array_to_sort) {
    if (array_to_sort.size() == 1) {
        return array_to_sort;
    }
    std::size_t const half_size = array_to_sort.size() / 2;

    std::vector<std::int64_t> first_half (array_to_sort.begin(), array_to_sort.begin() + half_size);
    std::vector<std::int64_t> second_half (array_to_sort.begin() + half_size, array_to_sort.end());

    first_half = MergeSort(first_half);
    second_half = MergeSort(second_half);

    return Merge(first_half, second_half);
}