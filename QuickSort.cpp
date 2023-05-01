/*
*    Brian Chairez
*
*    Quicksort Algorithm
*        Time Complexity:
*            Worst Case: O(n^2)
*            Average Case: O(nlogn)
*        Space Complexity:
*            O(n)
*/

#include <vector>
#include <utility>  //std::swap()

template <class T>
int partition(std::vector<T>& array, const int& low, const int& high) {
    // Pivot point will always be the last element of array/sub-array
    T pivot = array[high];

    // Temp index to keep track of the two partitions
    int i = low-1;

    for (int j = low; j < high; ++j) {
        if (array[j] <= pivot) {
            ++i;
            std::swap(array[i], array[j]);
        }
    }

    // Swap pivot into it's sorted location
    ++i;
    std::swap(array[i], array[high]);

    return i;
}

template <class T>
std::vector<T> QuickSort_(std::vector<T>& array, const int& low, const int& high) {
    if (low >= high || low < 0) {
        return array;
    }

    // Partitions the array and returns the partition index
    int part = partition(array, low, high);

    QuickSort_(array, low, part-1);
    QuickSort_(array, part+1, high);

    return array;
}

// Wrapper function for first recursion call
template <class T>
void QuickSort(std::vector<T>& array) {
    array = QuickSort_(array, 0, array.size()-1);
}
