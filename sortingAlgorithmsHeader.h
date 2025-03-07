#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <vector>
#include <algorithm> 

class Sorting {
private:
    template <typename T>
    void heapify(std::vector<T>&, int, int);
    template<typename T>
    void merge(std::vector<T>&, size_t, size_t, size_t);
    template <typename T>
    int partition(std::vector<T>& vec, size_t left, size_t right);
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
    void mergeSort(std::vector<T>&, size_t, size_t);
    template <typename T>
    void quickSort(std::vector<T>&, int, int);
    template <typename T>
    void selectionSort(std::vector<T>&);
};

#include "sortingAlgorithmsImplementation.tpp"
#endif