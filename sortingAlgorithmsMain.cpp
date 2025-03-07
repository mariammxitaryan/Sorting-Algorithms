#include "sortingAlgorithmsHeader.h"

int main() {
    Sorting sorting;

    std::vector<int> vec1 = {10, 7, 8, 9, 1, 5};
    std::vector<int> vec2 = {4, 3, 2, 1};
    std::vector<int> vec3 = {1, 2, 3, 4, 5};
    std::vector<int> vec4 = {5, 3, 8, 6, 2, 7, 4, 1};

    std::cout << "Testing Bubble Sort:" << std::endl;
    sorting.bubbleSort(vec1);
    for (const auto& val : vec1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Testing Insertion Sort:" << std::endl;
    sorting.insertionSort(vec2);
    for (const auto& val : vec2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Testing Bucket Sort:" << std::endl;
    sorting.bucketSort(vec3);
    for (const auto& val : vec3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;


    std::cout << "Testing Counting Sort:" << std::endl;
    sorting.countingSort(vec4);
    for (const auto& val : vec4) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Testing Heap Sort:" << std::endl;
    sorting.heapSort(vec1);
    for (const auto& val : vec1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Testing Merge Sort:" << std::endl;
    sorting.mergeSort(vec2, 0, vec2.size() - 1);
    for (const auto& val : vec2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Testing Quick Sort:" << std::endl;
    sorting.quickSort(vec3, 0, vec3.size() - 1);
    for (const auto& val : vec3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Testing Selection Sort:" << std::endl;
    sorting.selectionSort(vec4);
    for (const auto& val : vec4) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
