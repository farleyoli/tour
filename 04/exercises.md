# Problem A: Safe Integer Array

**Concepts Tested:**
- Exception handling in C++
- Implementing and using custom exceptions
- Basic array operations
- Resource Acquisition Is Initialization (RAII)

**Problem Statement:**
Design and implement a class named `SafeIntArray` that provides a safe wrapper around a basic integer array. This class should enforce bounds checking and throw a custom exception when an attempt is made to access an element outside the array's bounds.

1. **Array Implementation:**
   - Implement `SafeIntArray` to store integers in an internally managed array. The class should support operations to add elements (up to a fixed size for simplicity) and access elements by index.
   - The class should maintain an internal array of integers and track the current number of elements. Assume a maximum array size of 100 elements for simplicity.

2. **Custom Exception:**
   - Define a custom exception class named `IndexOutOfBoundsException` that inherits from `std::out_of_range`. This exception should be able to accept and store an error message upon initialization, including the invalid index accessed and the maximum valid index.

3. **Bounds Checking:**
   - Implement bounds checking in `SafeIntArray` by overloading the `operator[]` for both const and non-const access. If an attempt is made to access an element outside the array's current bounds, throw an `IndexOutOfBoundsException` with a meaningful error message.

4. **Exception Handling:**
   - Write a function named `testSafeIntArray` that demonstrates the use of `SafeIntArray`. In this function, attempt to access elements both within and outside the bounds of the array. Use try-catch blocks to catch the `IndexOutOfBoundsException` and print the error message to `std::cerr`.

**Technical Requirements:**
- The `SafeIntArray` must correctly manage the internal array, ensuring it does not allow access beyond the current number of elements or the maximum array size.
- The custom exception must provide a clear and informative message, ideally specifying the invalid index attempted and the current maximum valid index.
- Demonstrate proper use of exception handling, specifically how to catch specific exceptions and manage resources properly.

**Example Usage:**
```cpp
int main() {
    SafeIntArray safearray; // Initialize a SafeIntArray with a fixed capacity
    try {
        safearray.add(10);
        safearray.add(20);
        std::cout << "Accessing element at index 1: " << safearray[1] << std::endl;
        // This should throw an exception
        std::cout << "Accessing element at index 10: " << safearray[10] << std::endl;
    } catch (const IndexOutOfBoundsException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}
```
This problem focuses on ensuring you can apply exception handling to manage errors in a controlled manner, specifically within the context of array operations, without the added complexity of templates.
