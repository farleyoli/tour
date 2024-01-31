#include <cctype>
#include <ios>
#include <iostream>
#include <map>
#include <string>
using namespace std;


class Settings {
public:
    void toggleSetting(char setting) {
        if (states.count(setting) == 0)
            states[setting] = true;
        else
            states[setting] = !states[setting];
    }

    bool getSetting(char setting) {
        if (states.count(setting) == 0)
            return false;
        return states[setting];
    }
    void displaySettings() {
        for (const auto& pair : states) {
            char key = pair.first;
            bool state = pair.second;
            cout << "Key " << key << " has value " << boolalpha << state << endl;
        }
    }
private:
    map<char, bool> states;
};

string getOptions() {
    string ret = "\n";
    ret += "- Input 'd' to display all settings and their states\n";
    ret += "- Input 'q' to quit the menu\n";
    ret += "- Input any other character to toggle that character's setting (case-insensitivity)\n";
    return ret;
}

void settingsMenu(Settings& settings) {
    string options = getOptions();
    char input = 0;
    cout << options;
    cin >> input;
    while (true) {
        switch(input) {
            case 'q':
                return;
            case 'd':
                settings.displaySettings();
                break;
            default:
                settings.toggleSetting(tolower(input));
        }
        cout << options;
        cin >> input;
    }
}

int main() {
    Settings appSettings;
    settingsMenu(appSettings);  // Runs the menu loop
}
