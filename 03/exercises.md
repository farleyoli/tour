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

# Problem B: Namespace Management Utility

**Concepts Tested:**
- Understanding and usage of namespaces
- Function declaration and definition within namespaces
- Use of `using` declarations and directives

**Problem Statement:**
Create a namespace management utility that demonstrates the use of custom namespaces, interaction between different namespaces, and the use of `using` declarations and directives to manage scope and visibility of names. 

1. **Namespace Declaration and Function Implementation:**
   - Define a namespace named `UtilityFunctions`. Inside it, declare and define a function `void displayMessage()` that prints "Utility Function Message: Hello World!".
   - Define another namespace named `AdvancedMath`. Inside it, declare and define a function `double computeCircleArea(double radius)` that returns the area of a circle given the radius. Use the constant `pi` (3.14159) for calculations.

2. **Namespace Interaction and `using` Declaration:**
   - Define a third namespace named `MathApplication`. Inside it, create a function `void performComputation(double radius)` that computes the area of a circle by calling `AdvancedMath::computeCircleArea(radius)` and prints the result. 
   - Within `MathApplication`, use a `using` declaration to bring `displayMessage` from `UtilityFunctions` directly into scope, and call it at the beginning of `performComputation`.

3. **Global Scope Function with `using` Directive:**
   - In the global scope, declare and define a function `void runApp()`. Inside this function, use a `using` directive for `MathApplication` namespace and call `performComputation` with a radius of 5.0.
   - Ensure that `runApp` also calls `UtilityFunctions::displayMessage` directly, demonstrating the difference in name visibility due to the `using` directive.

**Technical Requirements:**
- Ensure that `computeCircleArea` uses the correct formula for calculating the area of a circle (\(Area = \pi \times radius^2\)).
- The `using` declaration in `MathApplication` should only apply to `displayMessage`, not to any other function from `UtilityFunctions`.
- The `using` directive in `runApp` should demonstrate how all members of `MathApplication` become accessible without namespace qualification.

**Example Usage:**
```cpp
int main() {
    runApp();
}
```

# Problem C: Vector Transformation Utility

**Concepts Tested:**
- Function arguments and return values
- Use of STL containers (std::vector)
- Passing arguments by const-reference
- Returning objects from functions
- Structured binding (C++17)

**Problem Statement:**
Design and implement a utility named `VectorTransformation` that performs various transformations on a vector of integers and returns the results in a structured manner. This utility will showcase understanding of efficient argument passing, use of STL containers, and modern C++ features like structured binding.

1. **Sum and Product Calculation:**
   - Implement a function `std::pair<int, int> calculateSumAndProduct(const std::vector<int>& vec)` that calculates both the sum and the product of all elements in the provided vector. The function should return these two values as a `std::pair`, with the sum as the first element and the product as the second.

2. **Filtered Copy:**
   - Implement a function `std::vector<int> copyIfGreaterThan(const std::vector<int>& vec, int threshold)` that returns a new vector containing only the elements of `vec` that are greater than a specified `threshold` value. This demonstrates passing large objects efficiently and returning by value.

3. **Modification by Reference:**
   - Implement a function `void incrementAllBy(std::vector<int>& vec, int increment)` that increments all elements of the vector `vec` by a given `increment` value. This function should modify the vector in place.

4. **Demonstrate Structured Binding (Corrected):**
   - In a function `void demonstrateStructuredBinding(const std::vector<int>& vec)`, use the `calculateSumAndProduct` function to get the sum and product of the provided vector `vec`, and then print these values using structured binding. This demonstrates the use of structured binding with functions returning multiple values.

**Technical Requirements:**
- `calculateSumAndProduct` should use a single loop to calculate both the sum and the product to ensure efficiency.
- `copyIfGreaterThan` should demonstrate understanding of STL containers and efficient object return mechanisms.
- `incrementAllBy` should modify the input vector in place, demonstrating the use of non-const references.
- Use structured binding in `demonstrateStructuredBinding` to unpack the returned pair from `calculateSumAndProduct`.

**Example Usage:**
```cpp
int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    VectorTransformation::demonstrateStructuredBinding(vec);

    auto filtered = VectorTransformation::copyIfGreaterThan(vec, 2);
    for (int val : filtered) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    VectorTransformation::incrementAllBy(vec, 5);
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
```
