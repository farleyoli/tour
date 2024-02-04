#include <cstring>
#include <iostream>
#include <vector>

union ConfigValue {
    int i;
    float f;
    char* s;
};

enum class ConfigType {
    INT, FLOAT, STRING
};

struct ConfigEntry {
    ConfigEntry(std::string _s, ConfigType _ct, ConfigValue _cf) {
        s = _s; ct = _ct; cf = _cf;
    }
    std::string s;
    ConfigType ct;
    ConfigValue cf;
};

class ConfigManager {
public:
    ~ConfigManager() {
        for (auto configEntry : ce) {
            if (configEntry.ct == ConfigType::STRING && configEntry.cf.s != nullptr) {
                delete[] configEntry.cf.s;
            }
        }
    }
    void addConfig(const std::string& name, int value) {
        ce.push_back(
            ConfigEntry(name, ConfigType::INT, ConfigValue {value})
        );
    }
    void addConfig(const std::string& name, float value) {
        ConfigValue cv;
        cv.f = value;
        ce.push_back(
            ConfigEntry(name, ConfigType::FLOAT, cv)
        );
    }
    void addConfig(const std::string& name, char* value) {
        ConfigValue cv;
        cv.s = value;
        cv.s = new char[std::strlen(value) + 1];
        std::strcpy(cv.s, value);
        ce.push_back(
            ConfigEntry(name, ConfigType::STRING, cv)
        );
    }
    bool getConfigValue(const std::string& name, int& outValue) {
        for (auto configEntry : ce) {
            if (configEntry.ct == ConfigType::INT && configEntry.s == name) {
                outValue = configEntry.cf.i;
                return true;
            }
        }
        return false;
    }
    bool getConfigValue(const std::string& name, float& outValue) {
        for (auto configEntry : ce) {
            if (configEntry.ct == ConfigType::FLOAT && configEntry.s == name) {
                outValue = configEntry.cf.f;
                return true;
            }
        }
        return false;
    }
    bool getConfigValue(const std::string& name, char* &outValue) {
        for (auto configEntry : ce) {
            if (configEntry.ct == ConfigType::STRING && configEntry.s == name) {
                outValue = new char[std::strlen(configEntry.cf.s) + 1];
                std::strcpy(outValue, configEntry.cf.s);
                return true;
            }
        }
        return false;
    }
private:
    std::vector<ConfigEntry> ce;
};

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

