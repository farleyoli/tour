# Problem A: Function Overloading and Default Arguments

**Concepts Tested:**
- Function Overloading
- Default Arguments
- Basic Input and Output

**Problem Statement:**
You are tasked with creating a set of overloaded functions named `displayInfo`. These functions will be used to display different types of information about a student. The student's details to be displayed are name, age, and GPA (Grade Point Average).

1. **Overloaded Function Definitions:**
    - Define a function `void displayInfo(const std::string& name)` that displays the student's name.
    - Define a function `void displayInfo(const std::string& name, int age)` that displays the student's name and age.
    - Define a function `void displayInfo(const std::string& name, int age, double gpa)` that displays the student's name, age, and GPA.

2. **Default Arguments:**
    - Modify the function `void displayInfo(const std::string& name, int age)` to have a default argument for `age` with the value `18`.
    - Modify the function `void displayInfo(const std::string& name, int age, double gpa)` to have default arguments for `age` with the value `18` and `gpa` with the value `0.0`.

**Technical Requirements:**
- The functions should output the information in a readable format, e.g., "Name: John, Age: 18, GPA: 3.5".
- Use default arguments only for the age and gpa parameters in the appropriate functions.
- Ensure that the correct function is called based on the number and type of arguments provided.

**Example Usage:**
```cpp
displayInfo("Alice"); // Outputs: Name: Alice
displayInfo("Bob", 20); // Outputs: Name: Bob, Age: 20
displayInfo("Charlie", 21, 3.7); // Outputs: Name: Charlie, Age: 21, GPA: 3.7
displayInfo("Diana", 0, 3.9); // Outputs: Name: Diana, Age: 0, GPA: 3.9
```

**Note:** You need to define the `displayInfo` functions with the specified signatures and implement them according to the problem statement. This problem tests your understanding of function overloading and the use of default arguments in C++.

# Problem B: Type Conversion and Arithmetic Operations

**Concepts Tested:**
- Type conversion (implicit and explicit)
- Arithmetic operations
- Variable initialization and auto type deduction

**Problem Statement:**
Create a program that demonstrates the concept of type conversion, arithmetic operations, and auto type deduction in C++. You are required to perform the following tasks:

1. **Variable Initialization and Arithmetic Operations:**
   - Initialize four variables: two `double` variables `d1` and `d2`, an `int` variable `i1`, and a `char` variable `ch1`. Use explicit values for initialization.
   - Perform arithmetic operations on these variables and store the results in new variables. You must include the following operations:
     - Addition of `d1` and `i1`.
     - Subtraction of `d2` from `ch1`.
     - Multiplication of `d1` and `d2`.
     - Division of `i1` by `d1`.

2. **Type Conversion and Arithmetic Error Handling:**
   - Demonstrate implicit type conversion by assigning the result of a double and int operation to an int variable. Comment on the result.
   - Attempt to assign a `double` value to an `int` variable using list initialization and handle the error gracefully with a comment explaining why the error occurs.

3. **Auto Type Deduction:**
   - Use `auto` keyword to declare two variables `autoVar1` and `autoVar2`.
   - Initialize `autoVar1` with an integer literal.
   - Initialize `autoVar2` with the result of a mixed-type arithmetic operation (e.g., an operation involving a `double` and an `int`).
   - Print the types of `autoVar1` and `autoVar2` using `typeid().name()` and comment on the observed behavior.

**Technical Requirements:**
- Ensure proper type conversion (implicit or explicit) where necessary.
- Handle narrowing conversions explicitly and comment on the behavior.
- Use `auto` for type deduction where appropriate and demonstrate understanding of when and why it's used.

**Example Usage:**
Your program does not need to take any input. The main focus is on demonstrating type conversion, arithmetic operations, and auto type deduction. Ensure that the code compiles and runs, displaying the results of the operations and the types of the variables.

```cpp
int main() {
    // Initialize variables
    double d1 = 3.14, d2 = 2.71;
    int i1 = 7;
    char ch1 = 'A';

    // Perform arithmetic operations
    // ... (your code here)

    // Demonstrate type conversion and error handling
    // ... (your code here)

    // Demonstrate auto type deduction
    // ... (your code here)

    return 0;
}
```

**Note:** You need to implement the arithmetic operations, type conversions, and demonstrate auto type deduction as per the specifications. This problem requires you to understand variable initialization, the differences between implicit and explicit type conversions, and the utility of auto in type deduction in C++.

# Problem C: Understanding Scope and Object Lifetime

**Concepts Tested:**
- Scope (local, class, namespace, global)
- Object lifetime and destruction

**Problem Statement:**
Create a program that illustrates the concept of scope (local, class, namespace, global) and the lifetime of objects in C++. You are required to perform the following tasks:

1. **Scope Demonstration:**
   - Define a global variable.
   - Create a function `scopeDemonstrator` with local variables and demonstrate the visibility of local, global, and function argument variables within the function.
   - Inside the function, attempt to access a local variable defined in a different function and comment on the result.

2. **Class Scope and Member Object Lifetime:**
   - Define a class `ClassWithMembers` with at least two member variables of different types.
   - In the constructor of `ClassWithMembers`, print a message indicating construction.
   - In the destructor of `ClassWithMembers`, print a message indicating destruction.
   - Demonstrate the creation and destruction of a `ClassWithMembers` object within a function, commenting on when the constructor and destructor are called.

3. **Namespace Scope:**
   - Define a namespace `MyNamespace` and declare a variable inside it.
   - Access this namespace member from the `main` function or another function, demonstrating the scope of namespace members.

4. **Object Lifetime and Destruction:**
   - In the `main` function, dynamically allocate an object of `ClassWithMembers` using `new`.
   - Demonstrate the control over the object's lifetime by explicitly destroying it using `delete` and commenting on when the destructor is called.

**Technical Requirements:**
- Ensure proper scope rules are followed and commented on in the code.
- Demonstrate understanding of object lifetime, especially with regards to dynamic memory allocation with `new` and deallocation with `delete`.

**Example Usage:**
Your program does not need to take any input. The main focus is on demonstrating scope, object lifetime, and the behavior of constructors and destructors.

```cpp
#include <iostream>

// Global variable
int globalVar = 10;

// Namespace definition
namespace MyNamespace {
    int namespaceVar = 20;
}

// Class definition
class ClassWithMembers {
public:
    ClassWithMembers() {
        std::cout << "Constructor called." << std::endl;
        // ...
    }
    
    ~ClassWithMembers() {
        std::cout << "Destructor called." << std::endl;
        // ...
    }
    
    // Member variables
    // ...
};

void scopeDemonstrator(int arg) {
    int localVar = 5;
    // Demonstrate scope visibility
    // ...
}

int main() {
    // Demonstrate scope, object lifetime, and destruction
    // ...
    
    return 0;
}
```

**Note:** You need to implement the functions, class, and namespace as per the specifications. This problem requires you to understand and demonstrate the concepts of scope and object lifetime in C++.

# Problem D: Constants and Compile-Time Evaluation

**Concepts Tested:**
- `const` and `constexpr` usage
- Immutable objects
- Compile-time function evaluation (`constexpr` and `consteval` functions)

**Problem Statement:**
Create a program that demonstrates the usage of `const` and `constexpr` in C++, and the concept of compile-time function evaluation. You are required to perform the following tasks:

1. **Constants Declaration and Usage:**
   - Declare a `constexpr` integer `constInt` and initialize it with a compile-time constant value.
   - Declare a `const` double `constDouble` and initialize it with the square root of a non-constant integer, illustrating runtime initialization.

2. **Compile-Time Function Evaluation:**
   - Define a `constexpr` function `constexprSquare` that computes the square of a number.
   - Use `constexprSquare` with a compile-time constant argument and store the result in a `constexpr` variable.
   - Attempt to use `constexprSquare` with a non-constant expression and store the result in a `const` variable, commenting on the difference in behavior.

3. **`consteval` Function Demonstration:**
   - Define a `consteval` function `constevalSquare` that computes the square of a number.
   - Demonstrate the usage of `constevalSquare` with a compile-time constant, and comment on the behavior when used with a non-constant expression.

4. **Complex `constexpr` Function:**
   - Define a `constexpr` function `nthPower` that computes the `n`th power of a number `x` (both `x` and `n` are function arguments).
   - Use `nthPower` with compile-time constants and with non-constant expressions, demonstrating both compile-time and runtime evaluation.

**Technical Requirements:**
- Ensure proper use of `const` and `constexpr` in variable declarations.
- Correctly implement and use `constexpr` and `consteval` functions.
- Demonstrate understanding of compile-time vs. runtime evaluation in the context of `constexpr` functions.

**Example Usage:**
Your program does not need to take any input. The main focus is on demonstrating the correct usage of `const`, `constexpr`, and `consteval`, and understanding their impact on compile-time and runtime behavior.

```cpp
#include <cmath>
#include <iostream>

// Constants declaration
constexpr int constInt = 10;
const double constDouble = std::sqrt(20);

// constexpr function
constexpr double constexprSquare(double x) {
    return x * x;
}

// consteval function
consteval double constevalSquare(double x) {
    return x * x;
}

// Complex constexpr function
constexpr double nthPower(double x, int n) {
    // ... (your implementation here)
}

int main() {
    // Demonstrate const and constexpr usage
    // ...

    // Demonstrate constexpr and consteval functions
    // ...

    // Demonstrate complex constexpr function
    // ...

    return 0;
}
```

**Note:** You need to implement the functions and demonstrate the use of `const`, `constexpr`, and `consteval` as per the specifications. This problem requires you to understand the nuances of constant expressions, compile-time function evaluation, and the role of immutability in program design.

# Problem E: String Analysis with CharAnalyzer

**Concepts Tested:**
- Pointers and Arrays
- Const correctness
- Iterating through arrays using pointers

**Problem Statement:**
Implement a utility class `CharAnalyzer` for analyzing characteristics of a C-style string (a zero-terminated array of characters). The class should provide functionalities to count occurrences of a specific character and check if the string is a palindrome. Note that the class should operate on `const char*`, ensuring that the string is not modified.

1. **Class Definition:** Define a class `CharAnalyzer` with a private member `const char* str`, which points to a C-style string.

2. **Constructor:** Implement a constructor for `CharAnalyzer` that takes a `const char*` and initializes the `str` member. The constructor should also ensure that `str` does not point to `nullptr`. If it does, handle it appropriately (e.g., throw an exception).

3. **Character Counting:** Implement a member function `int countChar(char ch)` that counts and returns the number of occurrences of `ch` in the string pointed to by `str`. Iterate through the string using pointers.

4. **Palindrome Check:** Implement a const member function `bool isPalindrome()` that returns `true` if the string is a palindrome, and `false` otherwise. A palindrome is a string that reads the same backward as forward. Ensure that you check for palindromes in an efficient manner, considering the symmetry of the problem.

**Technical Requirements:**
- In `countChar`, ensure efficient traversal of the string using pointers.
- In `isPalindrome`, avoid unnecessary comparisons or iterations.
- Handle the `nullptr` case in the constructor by throwing an exception or asserting.

**Example Usage:**

```cpp
const char* sampleStr = "level";
CharAnalyzer analyzer(sampleStr);

std::cout << analyzer.countChar('e') << '\n'; // Outputs 2
std::cout << std::boolalpha << analyzer.isPalindrome() << '\n'; // Outputs true
```

**Note:** You are required to implement the `CharAnalyzer` class and the specified member functions. This problem tests your understanding of pointers, arrays, and const correctness in C++. The operations should not modify the original string.

# Problem F: Custom Control Flow and Input Handling

**Concepts Tested:**
- Control Structures (if-statements, switch-statements)
- Loops (while-loops, for-loops)
- Standard Input and Output
- Data Validation and Error Handling

**Problem Statement:**
Design and implement a console-based menu system for a settings configuration of a hypothetical software. The system should allow users to view and modify settings through a series of inputs. Each setting is represented by a single character and can be toggled between `true` and `false`.

1. **Settings Representation:** 
    - Define a class `Settings` with a private member that is a `std::map<char, bool>` to hold setting states keyed by single characters.
    - Implement member functions:
        - `void toggleSetting(char setting)`: This function should toggle the boolean value of the given setting. If the setting does not exist, it should be added with a default value of `true`.
        - `bool getSetting(char setting)`: This function should return the current state of the given setting. If the setting does not exist, return `false`.

2. **Menu System Implementation:**
    - Implement a function `void settingsMenu(Settings& settings)` to handle user interactions.
    - The menu should present the user with options to:
        - Toggle settings by entering the corresponding character.
        - Display the current state of all settings.
        - Exit the menu.

3. **Input Handling and Validation:**
    - Ensure that the menu continues to prompt the user until they choose to exit.
    - Use a switch-statement to handle the different input options.
    - Provide feedback for invalid inputs.
    - Implement the exit functionality using a specific character input (e.g., 'q' for quit).

**Technical Requirements:**
- Use control structures effectively to handle different stages of the menu (reading input, processing commands, etc.).
- Ensure proper error handling for invalid inputs.
- The settings should be case-insensitive (e.g., 'A' and 'a' refer to the same setting).

**Example Usage:**
```cpp
Settings appSettings;
settingsMenu(appSettings);  // Runs the menu loop

// Inside the menu, the user can:
// - Input 'A'/'a' (or any other letter but 'd' and 'q') to toggle the 'a' setting (case-insensitivity)
// - Input 'd' to display all settings and their states
// - Input 'q' to quit the menu
```

**Note:** You need to define the `Settings` class, implement the required member functions, and create the `settingsMenu` function to handle user interactions as per the specifications. This problem requires understanding of control structures, class design, standard input/output, and basic error handling in C++.

# Problem G: Memory Inspector Utility

**Concepts Tested:**
- Pointer operations
- Reference operations
- Understanding of memory addresses
- Assignment vs. Initialization

**Problem Statement:**
Design and implement a utility named `MemoryInspector` that allows a user to inspect and manipulate memory locations of variables. The utility should demonstrate the handling of pointers, references, assignment, and initialization, reflecting a deep understanding of low-level memory operations.

1. **Memory Display Functionality:**
   - Implement a function `void displayMemoryAddress(int& variable)` that takes an integer reference, displays its value, and its memory address.
   - Overload `displayMemoryAddress` to also accept and handle pointers, displaying the memory address the pointer is pointing to, and the value stored at that address.

2. **Memory Modification Functionality:**
   - Implement a function `void modifyValue(int& variable, int newValue)` that takes an integer reference and a new integer value. The function should assign the new value to the referenced variable and display the old and new values of the variable.
   - Implement another function `void modifyValueThroughPointer(int* variablePtr, int newValue)` that takes an integer pointer, changes the value it points to, and displays the old and new values of the pointed-to variable.

3. **Assignment vs. Initialization Demonstration:**
   - In the main function, demonstrate the distinction between assignment and initialization using pointers and references. Use proper code comments to explain each operation, especially focusing on how assignment to a pointer changes the address it holds, while assignment to a reference changes the value of the referenced variable, not the binding of the reference.

**Technical Requirements:**
- `displayMemoryAddress` should properly handle both references and pointers.
- `modifyValue` and `modifyValueThroughPointer` should ensure the integrity of the operation is displayed (i.e., showing the value before and after the modification).
- Properly document the behavior of assignment vs. initialization, and how these concepts apply differently to pointers and references.

**Example Usage:**
```cpp
int main() {
    int x = 10;
    int y = 20;
    int* ptrX = &x;

    MemoryInspector::displayMemoryAddress(x);
    MemoryInspector::displayMemoryAddress(ptrX); 
    
    MemoryInspector::modifyValue(x, 15);
    MemoryInspector::modifyValueThroughPointer(&y, 25); 
    
    // Demonstration of Assignment vs Initialization
    // ... (your demonstration here with appropriate comments)
}
```

**Note:** The `MemoryInspector` utility should encapsulate the functionality to display and modify memory, showcasing a deep understanding of pointers, references, assignment, and initialization. Be meticulous in handling these low-level concepts to ensure the utility is robust and informative.
