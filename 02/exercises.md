# Problem A: Vector Analysis Utility

**Concepts Tested:**
- Understanding and usage of structures
- Dynamic memory allocation
- Pointer operations
- Function implementation and argument passing

**Problem Statement:**
Develop a utility named `VectorAnalysis` that allows a user to perform operations on a `Vector` structure. The `Vector` structure holds a pointer to double elements and an integer representing the size of the vector. This utility should demonstrate a deep understanding of structures, dynamic memory management, and pointer operations.

1. **Vector Initialization Functionality:**
   - Implement a function `void vectorInit(Vector& v, int size)` that initializes a `Vector` variable. The function should allocate an array of `size` doubles and set the `sz` member of the vector. Ensure that memory allocation is successful, and handle potential memory allocation failures appropriately.

2. **Vector Summation Functionality:**
   - Implement a function `double vectorSum(const Vector& v)` that returns the sum of all elements in the `Vector`. Ensure that the function does not modify the original vector.

3. **Vector Memory Deallocation:**
   - Implement a function `void vectorFree(Vector& v)` that deallocates the memory allocated for the `Vector`'s elements and sets the `sz` member to zero. Ensure that the function handles the case where the vector is already empty or uninitialized.

4. **Vector Print Functionality:**
   - Implement a function `void printVector(const Vector& v)` that prints all elements of the `Vector` in a formatted manner (e.g., `[elem1, elem2, elem3, ..., elemN]`).

**Technical Requirements:**
- `vectorInit` must allocate memory dynamically and handle allocation failures.
- `vectorSum` should not alter the contents or structure of the `Vector`.
- `vectorFree` should safely deallocate memory and properly handle vectors that are empty or uninitialized.
- `printVector` should display the contents of the vector in a human-readable format.

**Example Usage:**
```cpp
int main() {
    Vector v;
    vectorInit(v, 5);
    
    // Assuming the user inputs 5 values: 1.0, 2.0, 3.0, 4.0, 5.0
    for (int i = 0; i < v.sz; ++i) {
        std::cin >> v.elem[i];
    }

    printVector(v); // Output: [1.0, 2.0, 3.0, 4.0, 5.0]
    
    std::cout << "Sum of vector elements: " << vectorSum(v) << std::endl; // Output: 15.0
    vectorFree(v);
    printVector(v); // Output: []
}
``` 
