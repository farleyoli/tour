#include <iostream>
using namespace std;

int main() {
    // Initialize variables
    double d1 = 3.14, d2 = 2.71;
    int i1 = 7;
    char ch1 = 'A';

    // Perform arithmetic operations
    double di = d1 + i1;
    double dc = d2 + ch1;
    double dd = d1 * d2;
    double di2 = i1 / d1;

    // Demonstrate type conversion and error handling
    int a = 3.4 + 1;
    // int b {3.18};  // this causes a compilation error because double cannot be narrowed to int
    int b {static_cast<int>(3.18)};

    // Demonstrate auto type deduction
    auto autoVar1 = 3;
    auto autoVar2 = 3.13 + 2;

    cout << "The type of autoVar1 is " << typeid(autoVar1).name() << "\n";
    cout << "The type of autoVar2 is " << typeid(autoVar2).name() << "\n";

    return 0;
}

