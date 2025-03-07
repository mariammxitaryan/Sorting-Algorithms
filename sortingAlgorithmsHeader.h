#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <vector>
#include <algorithm> 

class Sorting {
public:
    template <typename T>
    void bubbleSort(std::vector<T>&);
    template <typename T>
    void insertionSort(std::vector<T>&);
    template <typename T>
    void bucketSort(std::vector<T>&);
    template <typename T>
    void countingSort(std::vector<T>&);
    template <typename T>
    void heapSort(std::vector<T>&);
    template <typename T>
    void mergeSort(std::vector<T>&);
    template <typename T>
    void quickSort(std::vector<T>&);
    template <typename T>
    void radixSort(std::vector<T>&);
    template <typename T>
    void selectionSort(std::vector<T>&);
};

#include "sortingAlgorithmsImplementation.tpp"
#endif