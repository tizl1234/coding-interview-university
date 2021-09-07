#include <iostream>
#include <stdlib.h>
#include <memory>

template <class Item>
void Exch(Item &A, Item &B) {
    Item t = A; A = B; B = t;
}

template <class Item>
void CompareAndExch(Item &A, Item &B) {
    if (B < A) { Exch(A,B); }  
}

template <class Item>
void Selection(Item a[], int l, int r) {
    for (int i = l; i < r; ++i) {
        int min = i; // select min element
        for (int j = i + 1; j <= r; ++j)  {
            if (a[j] < a[min]) min = j; // select new min
        }
        Exch(a[i], a[min]); //size - 1 exchanges 
    }
}

template <class Item>
void Insertion(Item a[], int l, int r) {
    int i;
    //find sentinel key (least element in the array)
    //and move it to beginning
    for (i = r; i > l; --i) {
        CompareAndExch(a[i-1], a[i]); 
    }
    //insertion itself
    //start from next element from sentinel key
    for (i = l+2; i<=r; ++i) {
        int j = i; Item v = a[i];//cache value to insert;
        //shift element untill we find place to insert
        while (v < a[j - 1]) {
            a[j] = a[j-1]; --j;
        }
        //insert element
        a[j] = v;
    }
}

template<class Item>
void Bubble(Item a[], int l, int r) {
    for (int i = l; i < r; ++i) {
        for (int j = r; j > i; --j) {
            CompareAndExch(a[j-1], a[j]);
        }
    }
}

template<class Item>
int Partition(Item a[], int l, int r) {
    int i = l - 1, j = r; Item v = a[r];
    while (1) {
        while (a[++i] < v);
        while (v < a[--j]) { if(j == l) break;} 
        if (i >= j) break;
        Exch(a[i], a[j]);
    }
    Exch(a[i], a[r]);
    return i;
}

template <class Item>
void Quicksort(Item a[], int l, int r) {
    if (r <= l) {
        return;
    }
    int i = Partition(a, l, r);
    Quicksort(a, l, i - 1);
    Quicksort(a, i + 1, r);
}

// template<class Item>
// void MergeAB(Item c[], Item a[], int N, Item b[], int M) {
//     for (int i = 0, j = 0, k = 0; k < N+M; ++k) {
//         //if a is deplited take elements form b
//         if (i == N) { c[k] = b[j++]; continue; }
//         //if b is deplited take elements from a
//         if (j == M) { c[k] = a[i++]; continue; }
//         //take the least element of two
//         c[k] = (a[i] < b[j]) ? a[i++] : b[j++];
//     }
// }

template<class Item>
void Merge(Item a[], int l, int m, int r) {
    int i; int j;
    auto aux = std::unique_ptr<Item[]>(new Item[l + r]);

    for (i = m+1; i > l; --i) { aux[i-1] = a[i-1]; }
    for (j = m; j < r; ++j) { aux[r+m-j] = a[j+1]; }

    for (int k = l; k <= r; ++k) {
        if (aux[j] < aux[i]) {
            a[k] = aux[j--];
        } else {
            a[k] = aux[i++];
        }
    }
}
template <class Item>
void MergeSort(Item a[], int l, int r) {
    if (r <= l) return;

    int m = (r+l)/2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    Merge(a, l, m, r);
}

int main () {
    srand (time(NULL));
    int size = 10;
     std::int64_t* array = new std::int64_t[size];

    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 200 + 1;
    }
    std::cout << "Input: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ", ";
    }
    std::cout << std::endl;

    MergeSort(array, 0, size - 1);
    std::cout << "Output: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ", ";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

// void Merge(std::int64_t* array_to_merge, size_t left, size_t middle, size_t right) {
//     size_t i = left;
//     size_t j = middle + 1; //midpoint
//     size_t k = left;
//     auto temp = std::unique_ptr<std::int64_t[]>(new std::int64_t[left + right]);
    
//     // compare and put smaller value in temp[]
//     while (i <= middle && j <= right) {
//         if (array_to_merge[i] <= array_to_merge[j]) {
//             temp[k] = array_to_merge[i];
//             ++i; ++k;
//         } else {
//             temp[k] = array_to_merge[j];
//             ++j; ++k;
//         }
//     }

//     while (i <= middle) { // copying all elements from left subarray as it is
//         temp[k] = array_to_merge[i];
//         ++i; ++k;
//     }

//     while (j <= right) { // copying all elements from right subarray as it is
//         temp[k] = array_to_merge[j];
//         ++j; ++k;
//     }

//     // copying elements to original array
//     for (size_t p = left; p <= right; ++p) {
//         array_to_merge[p] = temp[p];
//     }
// }

// void MergeSort(std::int64_t* array_to_sort, size_t left, size_t right) {
//     if (left < right) {
//         std::size_t const middle = (left + right) / 2;

//         MergeSort(array_to_sort, left, middle);
//         MergeSort(array_to_sort, middle + 1, right);

//         Merge(array_to_sort, left, middle, right);
//     }
// }