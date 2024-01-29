#include <iostream>

using namespace std;

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
    }
    
    ~ClassWithMembers() {
        std::cout << "Destructor called." << std::endl;
    }
    
    // Member variables
    int x;
    double y;
};

void scopeDemonstrator() {
    int localVar = 5;

    cout << "Value of localVar is accessible in scopeDemonstrator: " << localVar << endl;
    cout << "Value of globalVar is accessible in scopeDemonstrator: " << globalVar << endl;
    cout << "Value of MyNamspace::namspaceVar is accessible in scopeDemonstrator: " << MyNamespace::namespaceVar << endl;
    // cout << "Value of localVarMain is not accessible in scopeDemonstrator: " << localVarMain << endl;
}

void classDemonstrator() {
    cout << "Object is created here..." << endl;
    ClassWithMembers obj;
    cout << "Object will be destroyed after this..." << endl;
}

int main() {
    int localVarMain = 3;

    scopeDemonstrator();
    classDemonstrator();
    cout << "Object is already destroyed at this point." << endl;

    ClassWithMembers* p = new ClassWithMembers();
    cout << "This is called in main before the object is deleted: " << endl;
    delete p;
    cout << "This is called in main after the object is deleted: " << endl;
    
    return 0;
}

