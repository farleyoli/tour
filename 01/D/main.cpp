#include <cmath>
#include <iostream>
#include <stdexcept>

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
    if (n < 0)
        throw std::invalid_argument("This function does not support negative arguments");
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        double sqrt = nthPower(x, n / 2);
        return sqrt * sqrt;
    } else {
        return x * nthPower(x, n - 1);
    }
}

int main() {
    // Demonstrate const and constexpr usage
    constexpr double constExprSq = constexprSquare((double) constInt); // this is evaluated at compile-time
    const double constExprVal = constexprSquare(11.2); // this is evaluated at run-time

    // Demonstrate constexpr and consteval functions
    constexpr double constEvalSq = constevalSquare((double) constInt); // this is evaluated at compile-time
    // const double constEvalVal = constevalSquare(11.2); // this does not compile

    // Demonstrate complex constexpr function
    constexpr double x = 3;
    constexpr int n = 3;
    constexpr double nthP = nthPower(x, n); // this is evaluated at compile-time
    std::cout << x << " to the power of " << n << " is " << nthP << std::endl;
    return 0;
}

