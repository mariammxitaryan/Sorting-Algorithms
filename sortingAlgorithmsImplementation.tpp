// ***********************************************************************
//                            Bubble Sort Algorithm
// ***********************************************************************
//
// ** Time Complexity: **
//  - Worst Case: O(n^2)    (Occurs when the list is in reverse order)
//  - Best Case: O(n)       (Occurs when the list is already sorted)
//
// ** Space Complexity: **
//  - O(1)                 (In-place sorting, no additional space required)
//
// ** Stability: **
//  - Stable               (Does not change the relative order of equal elements)
//
// ** Characteristics: **
//  - Comparison-based sorting algorithm
//  - Repeatedly swaps adjacent elements if they are in the wrong order
//  - Optimized with early termination when no swaps are made during a pass
//
// ** Invariant: **
//  - After each pass of the outer loop, the largest element in the unsorted part of the array
//    is guaranteed to be placed at the end of the current unsorted portion.
//  - The algorithm progressively reduces the unsorted portion of the array as the largest elements "bubble up".
//  - The invariant ensures that the last elements of the array are progressively sorted with each pass.
//
// ***********************************************************************

template <typename T>
void Sorting::bubbleSort(std::vector<T>& vec) {
    bool swapped{};
    size_t size{vec.size()};
    for (size_t i{}; i < size; ++i) {
        swapped = false;
        for (size_t j{}; j < size - i - 1; ++j) {
            if (vec[j + 1] < vec[j]) {
                std::swap(vec[j + 1], vec[j]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

// ***********************************************************************
//                            Insertion Sort Algorithm
// ***********************************************************************
//
// ** Time Complexity: **
//  - Worst Case: O(n^2)    (Occurs when the list is in reverse order)
//  - Best Case: O(n)       (Occurs when the list is already sorted)
//
// ** Space Complexity: **
//  - O(1)                 (In-place sorting, no additional space required)
//
// ** Stability: **
//  - Stable               (Does not change the relative order of equal elements)
//
// ** Characteristics: **
//  - Comparison-based sorting algorithm
//  - Builds the sorted array one element at a time by shifting elements to the right
//  - Efficient for small data sets or nearly sorted data
//  - Operates in-place, without requiring extra memory allocation
//
// ** Invariant: **
//  - At the start of each iteration of the outer loop, the sublist from the beginning up to the current index is sorted.
//  - The key element (the current element in the outer loop) is inserted into the sorted part by shifting larger elements to the right.
//  - After each pass, the portion of the array from index 0 to the current position is always sorted, and the remaining part is unsorted.
//
// ***********************************************************************

template <typename T>
void Sorting::insertionSort(std::vector<T>& vec) {
    size_t size{vec.size()};
    T key{};
    for (size_t i{1}; i < size; ++i) {
        size_t j{i - 1};
        key = vec[i];
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

// ***********************************************************************
//                            Bucket Sort Algorithm
// ***********************************************************************
//
// ** Time Complexity: **
//  - Worst Case: O(n^2)     (Occurs when all elements are placed in the same bucket, and sorting within each bucket takes O(n) time)
//  - Best Case: O(n+k)       (Occurs when elements are uniformly distributed and each bucket has a small number of elements, where k is the number of buckets)
//  - Average Case: O(n+k)    (Average case assuming uniform distribution of input data)
//
// ** Space Complexity: **
//  - O(n+k)                 (Requires space for the buckets and the output array)
//
// ** Stability: **
//  - Stable                 (If stable sorting algorithms are used to sort individual buckets)
//
// ** Characteristics: **
//  - Distribution-based sorting algorithm
//  - Divides the input into several buckets, sorts each bucket individually, and then concatenates the buckets to produce the sorted list
//  - Efficient for data sets that are uniformly distributed over a range
//  - Often used for sorting floating-point numbers or integers within a specific range
//  - Can be used in parallel for improved performance on large data sets
//
// ** Invariant: **
//  - At the start of each iteration, the list is divided into several buckets based on the range of values.
//  - Each bucket is sorted individually using a different sorting algorithm (often Insertion Sort or Quick Sort).
//  - After all buckets are sorted, the elements from the buckets are concatenated in order to form the final sorted list.
//  - The final result maintains the relative order of elements within each bucket if the sorting algorithm used within the bucket is stable.
//
// ***********************************************************************

template <typename T>
void Sorting::bucketSort(std::vector<T>& vec) {
    size_t size{vec.size()};
    if (size <= 1) return;

    T minValue = *std::min_element(vec.begin(), vec.end());
    T maxValue = *std::max_element(vec.begin(), vec.end());

    std::vector<std::vector<T>> buckets(size);

    for (size_t i{}; i < size; ++i) {
        size_t bucketIndex{(vec[i] - minValue) * (size - 1) / (maxValue - minValue)};
        buckets[bucketIndex].push_back(vec[i]);
    }

    for (size_t i{}; i < size; ++i) {
        insertionSort(buckets[i]);
    }

    size_t index{};
    for (size_t i{}; i < size; ++i) {
        for (size_t j{}; j < buckets[i].size(); ++j) {
            vec[index++] = buckets[i][j];
        }
    }
}

// ***********************************************************************
//                            Counting Sort Algorithm
// ***********************************************************************
//
// ** Time Complexity: **
//  - Worst Case: O(n+k)     (Where n is the number of elements in the input and k is the range of the input values)
//  - Best Case: O(n+k)       (Occurs in all cases as the algorithm must process all elements and the range of values)
//  - Average Case: O(n+k)    (As the algorithm always processes the input and the range)
//
// ** Space Complexity: **
//  - O(k)                   (Requires space for the counting array based on the range of input values)
//
// ** Stability: **
//  - Stable                 (Preserves the relative order of equal elements)
//
// ** Characteristics: **
//  - Non-comparison-based sorting algorithm
//  - Assumes that input values are integers within a specific range
//  - Works by counting the occurrences of each element in the input and using those counts to place the elements in the correct position
//  - Efficient for sorting data with a limited range of values, especially when the range is not significantly larger than the number of elements
//  - Can be used for integer sorting and sorting certain non-negative types like integers or characters
//
// ** Invariant: **
//  - At the start of the algorithm, a counting array is initialized to store the frequency of each value in the input.
//  - For each element in the input, its count is incremented in the corresponding index of the counting array.
//  - The counting array is then transformed into a cumulative count array, which represents the position of each element in the sorted order.
//  - Elements are placed in their correct position by iterating through the input and using the cumulative counts, ensuring stability and preserving the relative order of equal elements.
//
// ***********************************************************************

template <typename T>
void Sorting::countingSort(std::vector<T>& vec) {
    size_t size{vec.size()};
    std::vector<T> tmp(size);
    T max = *std::max_element(vec.begin(), vec.end());
    T min = *std::min_element(vec.begin(), vec.end());
    if (min == max) {
        std::cout << "Vec is already sorted.\n";
        return;
    }
    int shift{-min};
    size_t range = max - min + 1;
    std::vector<size_t> count(range, 0);
    for (size_t i{}; i < size; ++i) {
        ++count[vec[i] + shift];
    }
    for (size_t i{1}; i < range; ++i) {
        count[i] += count[i - 1]; 
    }
    for (int i = size - 1; i >= 0; --i) {
        tmp[--count[vec[i] + shift]] = vec[i];
    }
    for (int i{}; i < size; ++i) {
        vec[i] = tmp[i];
    }
}

// ***********************************************************************
//                            Heap Sort Algorithm
// ***********************************************************************
//
// ** Time Complexity: **
//  - Worst Case: O(n log n)    (Occurs in all cases, as both heapify and the 
//                               extraction process take O(log n) time)
//  - Best Case: O(n log n)     (Even for a nearly sorted input, heapify and 
//                               extraction require O(log n) time)
//  - Average Case: O(n log n)  (Similar to the worst case)
//
// ** Space Complexity: **
//  - O(1)                      (In-place sorting, no additional space required)
//
// ** Stability: **
//  - Not Stable                (The relative order of equal elements may change)
//
// ** Characteristics: **
//  - Comparison-based sorting algorithm
//  - A variation of selection sort that repeatedly selects the largest element 
//    from the unsorted part of the array and swaps it with the root of the heap.
//  - Builds a binary heap (max-heap or min-heap) and uses this structure to 
//    efficiently extract the maximum (or minimum) element.
//  - Works by repeatedly heapifying the input to maintain the heap property.
//  - It’s an in-place sorting algorithm with a guaranteed time complexity of O(n log n), 
//    making it efficient for large datasets.
//
// ** Invariant: **
//  - At the start of the algorithm, the input array is converted into a heap. 
//    A heap is a complete binary tree where the parent node is greater than 
//    (in max-heap) or less than (in min-heap) the values of its child nodes.
//  - The heap property is maintained after each insertion and removal of elements, 
//    ensuring that the largest element is always at the root in a max-heap.
//  - In each iteration of the sorting process, the largest element is moved to the end 
//    of the array by swapping it with the root of the heap, followed by reheapification 
//    of the remaining heap to restore the heap property.
//  - After n-1 swaps and heapifications, the array is sorted in ascending order.
//
// ***********************************************************************

template <typename T>
void Sorting::heapify(std::vector<T>& vec, int n, int i) {
    int largest{i};
    int left{2 * i + 1};
    int right{2 * i + 2};

    if (left < n && vec[left] > vec[largest]) {
        largest = left;
    }

    if (right < n && vec[right] > vec[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(vec[i], vec[largest]);
        heapify(vec, n, largest);
    }
}

template <typename T>
void Sorting::heapSort(std::vector<T>& vec) {
    size_t size{vec.size()};
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(vec, size, i);
    }
    for (size_t i{size - 1}; i > 0; --i) {
        std::swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

// ***********************************************************************
//                            Merge Sort Algorithm
// ***********************************************************************
//
// ** Time Complexity: **
//  - Worst Case: O(n log n)    (Occurs in all cases, since the list is 
//                               repeatedly divided in half and merged)
//  - Best Case: O(n log n)     (Occurs in all cases, as merge sort divides 
//                               the list in half and merges it)
//  - Average Case: O(n log n)  (Divide and conquer approach, consistently 
//                               takes O(n log n) time)
//
// ** Space Complexity: **
//  - O(n)                      (Requires extra space to store temporary arrays 
//                               during the merge process)
//
// ** Stability: **
//  - Stable                    (Does not change the relative order of equal elements)
//
// ** Characteristics: **
//  - Comparison-based sorting algorithm
//  - A divide-and-conquer sorting algorithm that works by recursively 
//    splitting the array into two halves, sorting those halves, and then merging 
//    them back together in sorted order.
//  - The merging process ensures that the two halves are combined in sorted 
//    order by comparing the elements from each half in turn and placing the 
//    smaller element into the original array.
//  - Efficient for large datasets but requires additional space for temporary arrays.
//  - Works well for sorting linked lists as well, and is stable (maintains the 
//    relative order of equal elements).
//
// ** Invariant: **
//  - The array is recursively divided into halves until sub-arrays of size 1 are reached, 
//    which are inherently sorted.
//  - During the merging phase, two sorted sub-arrays (left and right) are combined in 
//    sorted order by comparing their elements and inserting them back into the original 
//    array. The merging process continues until the entire array is sorted.
//  - After all recursive calls, the original array is sorted in ascending order.
//
// ***********************************************************************

template <typename T>
void Sorting::merge(std::vector<T>& vec, size_t left, size_t mid, size_t right) {
    size_t leftSize{mid - left + 1};
    size_t rightSize{right - mid};
    std::vector<T> L(leftSize);
    std::vector<T> R(rightSize);

    for (size_t i{}; i < leftSize; ++i) {
        L[i] = vec[left + i];
    }

    for (size_t i{}; i < rightSize; ++i) {
        R[i] = vec[mid + 1 + i];
    }
   
    size_t i{}, j{}, k{left};
    while (i < leftSize && j < rightSize) {
        if (L[i] < R[j]) {
            vec[k] = L[i];
            ++i;
        }
        else {
            vec[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < leftSize) {
        vec[k++] = L[i++];
    }
    while (j < rightSize) {
        vec[k++] = R[j++];
    }
}
 
template <typename T>
void Sorting::mergeSort(std::vector<T>& vec, size_t left, size_t right) {
    if (left < right) {
        size_t mid{left + (right - left) / 2};
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}

// ***********************************************************************
//                            Quick Sort Algorithm
// ***********************************************************************
//
// ** Time Complexity: **
//  - Worst Case: O(n^2)     (Occurs when the pivot is the smallest or largest 
//                            element in the array, resulting in unbalanced partitions)
//  - Best Case: O(n log n)  (Occurs when the pivot divides the array into 
//                            nearly equal halves)
//  - Average Case: O(n log n) (Occurs in most cases when the pivot divides 
//                            the array into reasonably balanced parts)
//
// ** Space Complexity: **
//  - O(log n)               (Auxiliary space due to recursive call stack)
//
// ** Stability: **
//  - Unstable               (May change the relative order of equal elements)
//
// ** Characteristics: **
//  - Comparison-based sorting algorithm
//  - A divide-and-conquer sorting algorithm that works by selecting a "pivot" element 
//    from the array and partitioning the other elements into two sub-arrays according 
//    to whether they are less than or greater than the pivot.
//  - The sub-arrays are then sorted recursively.
//  - The efficiency of Quick Sort depends heavily on the choice of pivot: 
//    a good choice results in O(n log n) time complexity, while a poor choice can degrade 
//    to O(n^2).
//  - In practice, Quick Sort is one of the fastest sorting algorithms, especially 
//    for large datasets, and is often used in standard libraries.
//  - It operates in-place, meaning it doesn't require extra memory except for the 
//    recursion stack.
//  - The algorithm is not stable, meaning equal elements might not maintain their 
//    relative order after sorting.
//
// ** Invariant: **
//  - At the start of each recursion, the pivot element is placed in its correct 
//    position in the sorted array, with all elements less than the pivot to the 
//    left and all elements greater than the pivot to the right.
//  - After partitioning, the pivot is "locked" in its final position, and the sub-arrays 
//    on either side of the pivot are recursively sorted.
//  - Once the recursion reaches sub-arrays of size 1 or 0, the sorting is complete.
//
// ***********************************************************************

template <typename T>
int Sorting::partition(std::vector<T>& vec, size_t left, size_t right) {
    size_t randomIndex = left + rand() % (right - left + 1);
    std::swap(vec[right], vec[randomIndex]);
    T pivot{vec[right]};

    int i = left - 1;
    for (size_t j{left}; j < right; ++j) {
        if (vec[j] < pivot) {
            ++i;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[right]);
    return i + 1;
}

template <typename T>
void Sorting::quickSort(std::vector<T>& vec, int left, int right) {
    if (left < right) {
        int pivotIndex{partition(vec, left, right)};
        quickSort(vec, left, pivotIndex - 1);
        quickSort(vec, pivotIndex + 1, right);
    }
}

// ***********************************************************************
//                            Selection Sort Algorithm
// ***********************************************************************
//
// ** Time Complexity: **
//  - Worst Case: O(n^2)     (Occurs regardless of the input, as Selection Sort 
//                            always performs a nested loop to find the minimum element)
//  - Best Case: O(n^2)      (Even if the array is already sorted, Selection Sort 
//                            still goes through the entire array)
//  - Average Case: O(n^2)   (Same as worst case, since it always performs n^2 operations)
//
// ** Space Complexity: **
//  - O(1)                   (In-place sorting, no extra space required for sorting)
//
// ** Stability: **
//  - Unstable               (May change the relative order of equal elements)
//
// ** Characteristics: **
//  - Comparison-based sorting algorithm
//  - Iteratively selects the smallest element from the unsorted portion of the array
//    and places it in its correct position in the sorted portion.
//  - The algorithm maintains two subarrays: one that is sorted (on the left) and 
//    another that is unsorted (on the right).
//  - The time complexity of Selection Sort is always O(n^2) because for each 
//    element, it searches the entire remaining unsorted array for the minimum element.
//  - While easy to implement, Selection Sort is inefficient on large lists, 
//    making it impractical for most datasets.
//  - Selection Sort operates in-place, meaning it does not require additional memory 
//    beyond the input array itself.
//
// ** Invariant: **
//  - After each iteration of the outer loop, the leftmost subarray is sorted 
//    (the smallest element from the unsorted part is selected and placed in 
//    its correct position).
//  - The rightmost part of the array is still unsorted, but the algorithm continues 
//    to reduce the unsorted portion by selecting the smallest element from it in 
//    subsequent iterations.
//  - At the end of the algorithm, the entire array is sorted.
//
// ***********************************************************************

template <typename T>
void Sorting::selectionSort(std::vector<T>& vec) {
    size_t smallestIndex{};
    size_t size{vec.size()};
    for (size_t i{}; i < size - 1; ++i) {
        smallestIndex = i;
        for (size_t j{i + 1}; j < size; ++j) {
            if (vec[j] < vec[smallestIndex]) {
                smallestIndex = j;
            }
        }
        if (smallestIndex != i) {
            std::swap(vec[i], vec[smallestIndex]);
        }
    }
}

