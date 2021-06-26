#include <iostream>
#include <memory>
#include <stdlib.h>

int main() {
    srand (time(NULL));
    
    size_t size = 10;
    auto array =  std::unique_ptr<std::int64_t []> (new std::int64_t[size]);

    for (size_t i = 0; i < size; ++i) {
        array[i] = rand() % 100 + 1;
    }

    for (size_t i = 1; i < size; ++i) {
        auto current = array[i];

        size_t j;
        for (j = i - 1; (j >= 0) && (array[j] > current); --j) {
            array[j + 1] = array[j];
        }

        array[j + 1] = current;
    }

    for (size_t i = 0; i < size; ++i) {
        std::cout << array[i] << std::endl;
    }

    return EXIT_SUCCESS;
}