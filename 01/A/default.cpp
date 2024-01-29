#include <iostream>
#include <string>

using namespace std;

void displayInfo(const string& name, int age = 18, double gpa = 0.0) {
    cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << "\n";
}

int main() {
    displayInfo("Alice"); 
    displayInfo("Bob", 20); 
    displayInfo("Charlie", 21, 3.7);
    displayInfo("Diana", 0, 3.9);
}
