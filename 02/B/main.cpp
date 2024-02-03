#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class DateTracker {
public:
    DateTracker(int capacity) {
        _size       = 0;
        _capacity   = capacity;
        days        = new int[capacity];
        months      = new int[capacity];
        years       = new int[capacity];
    }

    ~DateTracker() {
        delete[] years;
        delete[] months;
        delete[] days;
    }

    bool addDate(const string& date) {
        if (!isValidDate(date) || size() == capacity())
            return false;

        days[size()]    = day_cache;
        months[size()]  = month_cache;
        years[size()]   = year_cache;
        
        _size++;
        return true;
    }

    int capacity() {
        return _capacity;
    }

    int size() {
        return _size;
    }

    string operator[](int i) {
        ostringstream oss;
        oss << years[i] << '-' << setw(2) << setfill('0') << days[i] << '-' << setw(2) << setfill('0') << months[i];
        return oss.str();
    }
private:
    int _capacity;
    int _size;
    int* years;
    int* months;
    int* days;
    int year_cache;
    int month_cache;
    int day_cache;

    bool isLeapYear(int year) {
        if (year % 4 != 0) {
            return false; // not divisible by 4
        } else if (year % 100 != 0) {
            return true; // divisible by 4 but not by 100
        } else if (year % 400 == 0) {
            return true; // divisible by 400
        } else {
            return false; // divisible by 100 but not by 400
        }
    }

    bool isOnlyDigits(const std::string& str) {
        for (char c : str) {
            if (!isdigit(c)) {
                return false; // found a non-digit character
            }
        }
        return true; // all characters were digits
    }

    bool isValidDate(const string& date) {
        if(count(date.begin(), date.end(), '-') != 2)
            return false;
        int days_per_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        stringstream ss(date);

        string year;
        getline(ss, year, '-');
        if (!isOnlyDigits(year))
            return false;
        year_cache = stoi(year);
        if (isLeapYear(year_cache))
            days_per_month[1]++;

        string day;
        getline(ss, day, '-');
        if (!isOnlyDigits(day) || day.size() != 2)
            return false;
        day_cache = stoi(day);
        if (day_cache < 0)
            return false;

        string month;
        getline(ss, month, '-');
        if (!isOnlyDigits(month) || month.size() != 2)
            return false;
        month_cache = stoi(month);
        if (month_cache < 1 || month_cache > 12)
            return false;

        if(day_cache > days_per_month[month_cache])
            return false;

        return true;
    }
};

int main() {
    DateTracker dt(5); // Create a DateTracker with capacity for 5 dates

    // Adding dates
    assert(dt.addDate("2023-02-02")); // Valid date
    assert(dt.addDate("223-12-12")); // Valid date
    assert(dt.addDate("2022-02-02")); // Valid date
    assert(dt.addDate("223-11-12")); // Valid date
    assert(!dt.addDate("2023-02-30")); // Invalid date, should return false or handle appropriately
    assert(dt.addDate("2020-02-02")); // Valid date
    assert(!dt.addDate("223-12-12")); // Overcapacity

    // Accessing dates
    for (int i = 0; i < dt.size(); ++i) {
        cout << dt[i] << endl;  // Print valid dates
    }
}

