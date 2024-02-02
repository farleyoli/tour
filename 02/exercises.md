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

# Problem B: DateTracker Utility [*]

**Concepts Tested:**
- Class design and encapsulation
- Basic dynamic memory management
- Operator overloading for custom functionality
- Use of constructor, destructor, and member functions

**Problem Statement:**
Design and implement a utility named `DateTracker` that manages a dynamic list of dates. Each date is represented as a string in the format "YYYY-MM-DD". The utility should demonstrate class design, dynamic memory management, and operator overloading, emphasizing encapsulation and class mechanics in C++ without diving into matrices or advanced copy control mechanisms.

1. **Constructor and Memory Allocation:**
   - Implement a constructor `DateTracker(int capacity)` that initializes the utility with the capacity to hold a certain number of dates. Allocate memory dynamically for an array of string objects.

2. **Date Addition and Safety:**
   - Implement a function `bool addDate(const std::string& date)` that attempts to add a new date to the `DateTracker`. If the date is in the correct format and there's enough capacity, add the date and return true. Otherwise, return false.

3. **Date Retrieval:**
   - Overload the subscript operator `operator[]` to provide access to specific dates by index. Implement bounds checking. If an index is out of bounds, print an error message and exit the program.

4. **Capacity and Size Retrieval:**
   - Implement a function `int capacity()` that returns the total capacity of the `DateTracker`.
   - Implement a function `int size()` that returns the current number of dates stored in the `DateTracker`.

5. **Date Validation:**
   - Implement a private helper function `bool isValidDate(const std::string& date)` that checks if a given date string follows the "YYYY-MM-DD" format and represents a valid date.

**Technical Requirements:**
- The `DateTracker` class should properly encapsulate its data, making the array of dates and its size private.
- The subscript operator should perform bounds checking and exit the program with an error message if the index is out of range.
- Implement dynamic memory allocation in the constructor and provide comments reminding users to deallocate memory manually to avoid memory leaks.

**Example Usage:**
```cpp
int main() {
    DateTracker dt(5); // Create a DateTracker with capacity for 5 dates

    // Adding dates
    dt.addDate("2023-02-02"); // Valid date
    dt.addDate("2023-02-30"); // Invalid date, should return false or handle appropriately

    // Accessing dates
    for (int i = 0; i < dt.size(); ++i) {
        std::cout << dt[i] << std::endl;  // Print valid dates
    }

    // Reminder for manual memory deallocation
    std::cout << "\nRemember to deallocate memory used by DateTracker manually to avoid memory leaks." << std::endl;
}
```
In this problem, the focus shifts to managing a dynamic list of dates, ensuring proper class design, and handling basic dynamic memory without involving complex data structures like matrices or advanced memory management techniques.
