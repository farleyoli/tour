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
