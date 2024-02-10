#include <iostream>
namespace UtilityFunctions {
    void displayMessage() {
        std::cout << "Utility Function Message: Hello World!" << std::endl;
    }
}

namespace AdvancedMath {
    double computeCircleArea(double radius) {
        constexpr double pi {3.14159};
        return pi * radius * radius;
    }
}

namespace MathApplication {
    using UtilityFunctions::displayMessage;
    void performComputation(double radius) {
        displayMessage();
        std::cout << "The area of the circle is " << AdvancedMath::computeCircleArea(radius) << std::endl;
    }
}

void runApp() {
    using namespace MathApplication;
    performComputation(5.0);

    // calling a function from UtilityFunctions directly
    UtilityFunctions::displayMessage();
}

int main() {
    runApp();
}
