```markdown
# Sorting Algorithms

Welcome to the **Sorting Algorithms** project! 🎉

This repository contains various sorting algorithms implemented in C++ to help you understand how different sorting algorithms work and to test their efficiency. Whether you're learning sorting algorithms for the first time or want to optimize your knowledge, this project provides easy-to-understand code examples and explanations.

## 🚀 Algorithms Implemented

- **Bubble Sort**
- **Selection Sort**
- **Insertion Sort**
- **Merge Sort**
- **Quick Sort**
- **Heap Sort**
- **Counting Sort**
- **Radix Sort**

Each algorithm is implemented in a separate function for easy use and understanding. All algorithms are optimized for clarity and educational purposes, and each algorithm includes inline comments explaining the steps.

## 🛠️ Features

- **Generic Sorting**: Works with various data types like `int`, `double`, `char`, etc.
- **Complete Collection**: Includes classical and advanced sorting algorithms.
- **Easy Integration**: Integrate the sorting algorithms into your own C++ projects easily.

## 🖥️ How to Use

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/yourusername/sorting-algorithms.git
   ```

2. Navigate to the project directory:
   ```bash
   cd sorting-algorithms
   ```

3. Compile the code using g++:
   ```bash
   g++ -std=c++20 sortingAlgorithmsMain.cpp -o sortingAlgorithmsMain
   ```

4. Run the executable:
   ```bash
   ./sortingAlgorithmsMain
   ```

5. Enjoy testing the sorting algorithms! 🎉

## 📚 Example Code Usage

Here’s an example of how you can use the sorting algorithms in your own C++ code:

```cpp
#include "sortingAlgorithmsHeader.h"

int main() {
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};
    
    Sorting sorter;
    sorter.bubbleSort(vec); // You can try other sorting methods here

    for (int num : vec) {
        std::cout << num << " ";
    }
    return 0;
}
```

## 📈 Algorithm Complexity

| Algorithm        | Time Complexity (Best) | Time Complexity (Worst) | Space Complexity |
|------------------|------------------------|-------------------------|------------------|
| **Bubble Sort**  | O(n)                   | O(n²)                   | O(1)             |
| **Selection Sort**| O(n²)                 | O(n²)                   | O(1)             |
| **Insertion Sort**| O(n)                  | O(n²)                   | O(1)             |
| **Merge Sort**   | O(n log n)             | O(n log n)              | O(n)             |
| **Quick Sort**   | O(n log n)             | O(n²)                   | O(log n)         |
| **Heap Sort**    | O(n log n)             | O(n log n)              | O(1)             |
| **Counting Sort**| O(n+k)                 | O(n+k)                  | O(k)             |
| **Radix Sort**   | O(nk)                  | O(nk)                   | O(n+k)           |

Where:
- `n` is the number of elements in the array
- `k` is the range of the input values (for Counting Sort and Radix Sort)

## 💡 Why This Project?

Sorting algorithms are fundamental in computer science. This project helps you to:
- Understand the underlying principles of sorting algorithms.
- Compare the efficiency of different sorting methods.
- Implement the algorithms in your own projects.

## 🌟 Contributions

Contributions are welcome! Feel free to fork this project and make your improvements. If you have any suggestions or want to report a bug, create an issue or open a pull request.

Happy coding! 🚀

---

**Project maintained by [Mariam](https://github.com/mariam).**

```
