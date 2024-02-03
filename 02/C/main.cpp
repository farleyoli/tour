#include <iostream>
#include <ostream>

enum class TrafficLight { green, yellow, red };
enum class PedestrianSignal { walk, wait };

std::ostream& operator<<(std::ostream& os, TrafficLight light) {
    switch (light) {
        case TrafficLight::green: os << "green"; break;
        case TrafficLight::yellow: os << "yellow"; break;
        case TrafficLight::red: os << "red"; break;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, PedestrianSignal signal) {
    switch (signal) {
        case PedestrianSignal::walk: os << "walk"; break;
        case PedestrianSignal::wait: os << "wait"; break;
    }
    return os;
}

namespace SmartTrafficControl {
    void changeTrafficLightState(TrafficLight& light) {
        switch (light) {
            case TrafficLight::red:
                light = TrafficLight::green;
                break;
            case TrafficLight::green:
                light = TrafficLight::yellow;
                break;
            case TrafficLight::yellow:
                light = TrafficLight::red;
                break;
        }
    }

    void changePedestrianSignalState(PedestrianSignal& signal) {
        if (signal == PedestrianSignal::walk)
            signal = PedestrianSignal::wait;
        else
            signal = PedestrianSignal::walk;
    }

    void synchronizeSignals(TrafficLight& light, PedestrianSignal& signal) {
        if (light == TrafficLight::green || light == TrafficLight::yellow)
            signal = PedestrianSignal::wait;
        else
            signal = PedestrianSignal::walk;
    }

    void displayStates(const TrafficLight& light, const PedestrianSignal& signal) {
        std::cout << "Traffic light is " << light << " and pedestrian signal is " << signal << std::endl;
    }
};

int main() {
    TrafficLight trafficLight = TrafficLight::green;
    PedestrianSignal pedestrianSignal = PedestrianSignal::wait;

    SmartTrafficControl::displayStates(trafficLight, pedestrianSignal);

    SmartTrafficControl::changeTrafficLightState(trafficLight);

    SmartTrafficControl::synchronizeSignals(trafficLight, pedestrianSignal);
    SmartTrafficControl::displayStates(trafficLight, pedestrianSignal);

    SmartTrafficControl::changeTrafficLightState(trafficLight);

    SmartTrafficControl::synchronizeSignals(trafficLight, pedestrianSignal);
    SmartTrafficControl::displayStates(trafficLight, pedestrianSignal);
}

