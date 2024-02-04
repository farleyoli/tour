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

# Problem C: Smart Traffic Control System

**Concepts Tested:**
- Enum classes
- Operator overloading
- Scope resolution
- Explicit type conversion

**Problem Statement:**
Implement a namespace named `SmartTrafficControl` that encapsulates the functionality of a traffic control system using `enum class` for traffic lights and pedestrian signals. The system should change the state of traffic lights and pedestrian signals based on the current state, demonstrating an understanding of `enum class` properties, operator overloading, and explicit type conversions.

1. **Traffic Light and Pedestrian Signal Enums:**
   - Inside the `SmartTrafficControl` namespace, define an `enum class TrafficLight { green, yellow, red };` to represent the state of a traffic light.
   - Inside the `SmartTrafficControl` namespace, define an `enum class PedestrianSignal { walk, wait };` to represent the state of pedestrian signals.

2. **State Transition Functionality:**
   - Implement a function `void changeTrafficLightState(TrafficLight& light)` within the namespace that changes the state of the traffic light to the next logical state in the order green -> yellow -> red -> green.
   - Implement a function `void changePedestrianSignalState(PedestrianSignal& signal)` within the namespace that toggles the state of the pedestrian signal between walk and wait.

3. **Synchronization Logic:**
   - Ensure that the traffic light and pedestrian signals are synchronized. When the traffic light is green or yellow, the pedestrian signal should be wait. When the traffic light is red, the pedestrian signal should be walk.
   - Implement a function `void synchronizeSignals(const TrafficLight& light, PedestrianSignal& signal)` within the namespace that updates the pedestrian signal based on the traffic light's current state.

4. **Display Functionality:**
   - Implement a function `void displayStates(const TrafficLight& light, const PedestrianSignal& signal)` within the namespace that prints the current state of the traffic light and the pedestrian signal.

**Technical Requirements:**
- `changeTrafficLightState` and `changePedestrianSignalState` should handle state transitions correctly.
- `synchronizeSignals` should ensure the integrity of the traffic system by properly synchronizing the traffic light and pedestrian signal.
- Use explicit type conversion where necessary, especially when displaying the state of signals.
- Properly manage scope resolution and avoid implicit conversions between `enum class` values and integers.

**Example Usage:**
```cpp
namespace SmartTrafficControl {
    // Enum definitions
    // Function declarations
}

int main() {
    SmartTrafficControl::TrafficLight trafficLight = SmartTrafficControl::TrafficLight::green;
    SmartTrafficControl::PedestrianSignal pedestrianSignal = SmartTrafficControl::PedestrianSignal::wait;

    SmartTrafficControl::displayStates(trafficLight, pedestrianSignal);

    SmartTrafficControl::changeTrafficLightState(trafficLight);
    SmartTrafficControl::synchronizeSignals(trafficLight, pedestrianSignal);
    SmartTrafficControl::displayStates(trafficLight, pedestrianSignal);

    // More state changes and synchronization...
}
```

In this setup, `SmartTrafficControl` is a well-organized namespace containing all related functions and enum classes, providing a clear and structured approach to managing traffic light and pedestrian signal states.

# Problem D: Union-Based Configuration Manager

**Concepts Tested:**
- Union and structure integration
- Enumerations and type tracking
- Proper memory management
- Class encapsulation and abstraction

**Problem Statement:**
Design and implement a class named `ConfigManager` that utilizes a union to store one of several types of configuration values. These values could be integer (`int`), floating-point (`float`), or a C-style string (`char*`). Use an enumeration to track the type of value currently stored in the union. Ensure that the class properly manages memory, especially for the C-style string, and encapsulates the union to prevent misuse.

1. **Configuration Union and Type Tracking:**
   - Define a union `ConfigValue` that can hold an `int`, a `float`, or a `char*`.
   - Create an enumeration `ConfigType` with values `INT`, `FLOAT`, and `STRING` to track what type of data is currently stored in the union.
   - Define a structure `ConfigEntry` that contains a `string` to hold the name of the configuration, a `ConfigType` to hold the type of the configuration, and a `ConfigValue` union.

2. **Class Implementation:**
   - Implement the `ConfigManager` class.
   - It should have a private member of type `std::vector<ConfigEntry>` to store multiple configurations.
   - Implement member functions:
     - `void addConfig(const std::string& name, int value)`
     - `void addConfig(const std::string& name, float value)`
     - `void addConfig(const std::string& name, const char* value)`
     - Ensure proper memory management, especially for the `char*` strings (consider deep copying).
   
3. **Value Retrieval and Memory Management:**
   - Implement member functions to retrieve values:
     - `bool getConfigValue(const std::string& name, int& outValue)`
     - `bool getConfigValue(const std::string& name, float& outValue)`
     - `bool getConfigValue(const std::string& name, char* &outValue)` (allocate memory for the `outValue` and copy the string into it)
   - Implement a destructor to properly deallocate any memory allocated for the C-style strings in the union.

4. **Type Safety and Error Handling:**
   - Ensure that each `getConfigValue` function checks the type of the config entry before attempting to return it. If the types do not match, or if the config name does not exist, the function should return `false`.

**Technical Requirements:**
- `ConfigManager` should properly encapsulate the union and manage memory for `char*` strings.
- `addConfig` and `getConfigValue` functions should handle different data types correctly and safely.
- Ensure that the `ConfigManager` destructor properly deallocates memory to prevent memory leaks.

**Example Usage:**
```cpp
int main() {
    ConfigManager cm;
    cm.addConfig("max_connections", 100);
    cm.addConfig("timeout", 52.5f);
    cm.addConfig("hostname", "example.com");
    
    int maxConnections;
    float timeout;
    char* hostname = nullptr;
    
    if (cm.getConfigValue("max_connections", maxConnections)) {
        std::cout << "Max Connections: " << maxConnections << std::endl;
    }
    
    if (cm.getConfigValue("timeout", timeout)) {
        std::cout << "Timeout: " << timeout << std::endl;
    }
    
    if (cm.getConfigValue("hostname", hostname)) {
        std::cout << "Hostname: " << hostname << std::endl;
        delete[] hostname; // Deallocate memory allocated by getConfigValue
    }
}
```

In this problem, students are required to demonstrate their understanding of unions, enums, and class encapsulation while also ensuring proper memory management, particularly with raw pointers for strings.
