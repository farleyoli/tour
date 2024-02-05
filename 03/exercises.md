# Problem A: Traditional Header-Based Vector Management

**Concepts Tested:**
- Traditional C++ header files and separate compilation
- Vector operations
- Class design and encapsulation
- Basic file organization for C++ projects

**Problem Statement:**
Create a C++ application that manages `std::vector` of integers using traditional header files and separate compilation. The application will consist of a class `VectorManager` that encapsulates vector operations, and a main file that utilizes `VectorManager` to perform operations.

1. **VectorManager Class:**
   - Create a header file `VectorManager.h` that declares a class `VectorManager` with the following public member functions:
     - `void fillVector(int value, int count)`: Fills the vector with a given value, repeated `count` times.
     - `int getElementAtIndex(int index)`: Returns the element at the specified index. If the index is out of bounds, return -1.
     - `void printVector()`: Prints all elements of the vector to the console, formatted as `{elem1, elem2, ..., elemN}`.
   - Ensure that `VectorManager` encapsulates a private `std::vector<int>` member that these functions will operate on.
   - Implement the member functions of `VectorManager` in a separate source file `VectorManager.cpp`.

2. **Main Application File:**
   - Create a `main.cpp` file.
   - Include the `VectorManager.h` header file.
   - In `main.cpp`, demonstrate the following using `VectorManager`:
     - Create an instance of `VectorManager`.
     - Fill the vector with a specific value and count.
     - Print the vector.
     - Retrieve and print an element at a specific index.

**Technical Requirements:**
- The `VectorManager` class should be fully functional and encapsulate all vector-related operations.
- Proper organization of code into separate files (`VectorManager.h`, `VectorManager.cpp`, and `main.cpp`) should be maintained.
- Include guards or `#pragma once` directive should be used in `VectorManager.h` to prevent multiple inclusions.

**Example Usage in `main.cpp`:**
```cpp
#include "VectorManager.h"

int main() {
    VectorManager vm;
    vm.fillVector(5, 10); // Fill vector with 10 instances of the number 5
    vm.printVector(); // Print the vector
    int value = vm.getElementAtIndex(3); // Get value at index 3
    std::cout << "Value at index 3: " << value << std::endl;
    return 0;
}
```

**Note:**
- Ensure proper use of header files and separate source files for class definition and implementation.
- This problem focuses on traditional C++ project structure, encapsulation of vector operations within a class, and the separation of declaration and implementation, aligning with your current level of understanding and the common support of compilers.
