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

# Problem B: File Logger with Exception Handling

**Concepts Tested:**
- File I/O
- Custom Exception Classes
- Constructors, Destructors, and Resource Management
- Class Invariants and Preconditions

**Problem Statement:**
Design and implement a `FileLogger` class that provides a robust logging utility, writing messages to a file. This class should ensure safety and correctness by managing file resources properly and enforcing class invariants, especially in scenarios involving file access and operations. Your implementation must demonstrate proficient use of file I/O, exception handling, and resource management within a realistic application context.

1. **FileLogger Class Definition:**
   - Define a class `FileLogger` that encapsulates file operations for logging messages.
   - Include necessary private members, such as a `std::ofstream` for the file stream and a `std::string` for the file name.

2. **Constructor with File Opening:**
   - Implement a constructor `FileLogger(const std::string& fileName)` that attempts to open the file specified by `fileName` for writing. Use constructor initialization lists where appropriate.
   - The constructor must throw a custom exception `FileOpenException` if it fails to open the file, ensuring the class invariant that a valid, open file stream is maintained.

3. **Destructor for File Closure:**
   - Implement a destructor that ensures the file stream is properly closed, preventing resource leaks.

4. **Custom Exception Classes:**
   - Define a custom exception class `FileOpenException` to report failures in opening the file.
   - Optionally, define another custom exception class `WriteException` to report failures in writing to the file.

5. **Logging Functionality with Exception Handling:**
   - Implement a member function `void log(const std::string& message)` that writes `message` to the file, followed by a newline character. This function must ensure that the write operation succeeds and throw `WriteException` if it fails.

6. **Demonstration of Resource Management and Exception Handling:**
   - Show how your class handles scenarios where file operations could lead to exceptions being thrown, such as during construction or logging, and demonstrate the safe release of resources.

**Technical Requirements:**
- The constructor must validate its arguments and manage file resources correctly, using exceptions to handle errors.
- Implement proper resource management to ensure file streams are correctly managed.
- Use custom exceptions to provide meaningful error handling and reporting.
- Ensure the class adheres to its invariants by validating preconditions and maintaining consistent states.

**Example Usage:**
```cpp
int main() {
    try {
        FileLogger logger("log.txt");
        logger.log("Application started");
        // Additional logging
    } catch (const FileOpenException& e) {
        std::cerr << "Failed to open log file: " << e.what() << '\n';
    } catch (const WriteException& e) {
        std::cerr << "Failed to write to log file: " << e.what() << '\n';
    }
}
```
This problem emphasizes practical application of class design principles, focusing on resource management, exception handling, and the enforcement of class invariants, reflecting a realistic use case in software development with C++.

# Problem C: Network Connection Simulator

**Concepts Tested:**
- Exception handling
- Simulating external resource management
- Use of error codes for expected failures
- Use of `noexcept`

**Problem Statement:**
Design and implement a class named `NetworkConnectionSimulator` that simulates basic network operations and error handling mechanisms in C++, focusing on exception handling, error codes, and unrecoverable errors simulation. Error should be simulated with random number generators.

1. **Connection Establishment:**
   - Implement a function `bool connect(const std::string& address)` that attempts to establish a connection to a given network address. This function should return a boolean indicating success (`true`) or failure (`false`) instead of throwing an exception, as connection failures are considered normal and expected errors that the immediate caller can handle.

2. **Data Transmission:**
   - Implement a function `void sendData(const std::string& data)` that simulates sending data over the established connection. If the connection is not established or if sending fails in a way that cannot be immediately handled, this function should throw an exception.

3. **Data Reception:**
   - Implement a function `std::string receiveData()` that simulates receiving data over the network connection. If the connection is not established or if receiving fails in an unexpected way, this function should throw an exception.

4. **Forced Disconnection and Termination:**
   - Implement a function `void forceDisconnect()` marked with `noexcept`. This function simulates a critical failure that leads to forced disconnection. If an exception is thrown within this function, the program should terminate. Use this function to demonstrate handling of errors that are considered unrecoverable within the context of your simulation.

**Technical Requirements:**
- `connect` should use error codes (returning `true` or `false`) to communicate failure instead of exceptions, as connection failures are expected and should be handled by the caller.
- `sendData` and `receiveData` should throw exceptions for errors that cannot be handled locally, as these represent unexpected failures that the immediate caller is likely not equipped to handle.
- `forceDisconnect` with `noexcept` should be used to simulate handling of unrecoverable errors, leading to program termination if an error occurs within.

**Example Usage:**
```cpp
int main() {
    NetworkConnectionSimulator simulator;

    // Attempt to connect, handle failure with error code
    if (!simulator.connect("http://example.com")) {
        std::cerr << "Failed to establish a connection." << std::endl;
        return -1;
    }

    try {
        simulator.sendData("Hello, World!");
        std::string response = simulator.receiveData();
        std::cout << "Received response: " << response << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred during data transmission: " << e.what() << std::endl;
    }

    // Demonstrate noexcept function
    simulator.forceDisconnect(); // This should be designed to show how terminate is called on errors
}
```

# Problem D: Customized Assert Library

**Concepts Tested:**
- Function overloading
- Pointer operations
- Control flow with exceptions
- Custom error handling

**Problem Statement:**
Expand the provided basic assertion utility into a more robust and versatile assertion library named `CustomAssert`. Your implementation should demonstrate advanced C++ features such as function overloading, exception handling, and pointer safety. The goal is to provide a tool that aids in debugging and validating program correctness under various conditions.

1. **Enhanced Assertion with Exception Throwing:**
   - Implement a function `void assertOrThrow(bool condition, const std::string& errorMessage)` that checks a condition; if the condition is `false`, it throws a custom exception `AssertionFailedException` with the provided error message.
   - The `AssertionFailedException` should be a custom exception class derived from `std::exception` and must override the `what()` method to return the error message.

2. **Null Pointer Assertion:**
   - Implement a template function `void assertNotNull(T* ptr, const std::string& errorMessage)` that checks if a given pointer is not `nullptr`. If the pointer is `nullptr`, it throws an `AssertionFailedException` with the provided error message.
   - This function should be usable with pointers to any type (e.g., `int*`, `double*`, `SomeClass*`).

3. **Equality Assertion with Custom Error Messages:**
   - Implement a template function `void assertEquals(T expected, T actual, const std::string& errorMessage)` that checks if two provided values are equal. If not, it throws an `AssertionFailedException` with the provided error message.
   - This function should work with any type that supports the `==` operator, providing flexibility in comparing values of basic data types or objects.

**Technical Requirements:**
- `assertOrThrow` must correctly identify failing conditions and throw exceptions accordingly.
- `assertNotNull` should provide a clear mechanism for pointer safety checks, throwing exceptions for null pointers.
- `assertEquals` should facilitate easy comparison of expected vs. actual values, enhancing test reliability.
- Custom exception `AssertionFailedException` must be properly defined and utilized in all relevant functions.

**Example Usage:**
```cpp
class SomeClass {
    // SomeClass definition
};

int main() {
    CustomAssert::assertOrThrow(true, "This should pass without an exception.");

    int x = 10;
    CustomAssert::assertNotNull(&x, "x should not be nullptr.");

    SomeClass* obj = new SomeClass();
    CustomAssert::assertNotNull(obj, "obj should not be nullptr.");

    CustomAssert::assertEquals(10, x, "x should be equal to 10.");
    
    try {
        CustomAssert::assertOrThrow(false, "This should throw an exception.");
    } catch (const AssertionFailedException& e) {
        std::cout << e.what() << std::endl;
    }

    // Ensure proper cleanup
    delete obj;
}
```

This problem challenges you to implement a feature-rich assertion library that can significantly aid in developing robust C++ applications by providing detailed feedback on failure conditions.
