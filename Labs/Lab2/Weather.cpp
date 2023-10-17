/*---Miguel Angel Gonzalez Mauricio
  ---Programming Fundamentals II
  ---COSC-1437
  ---Instructor: Brian Koontz
  */
  /*---Write (g++ -o Weather Weather.cpp) and (.\Weather.exe) to run the program on the terminal terminal*/
#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX_MONTHS = 12;

// Array of month names
const string MONTH_NAMES[MAX_MONTHS] = {
    "January", "February", "March", "April",
    "May", "June", "July", "August",
    "September", "October", "November", "December"
};

struct WeatherData {
    string month;
    double totalRainfall;
    double highTemperature;
    double lowTemperature;
    double averageTemperature;
};

void inputWeatherData(WeatherData data[], int numMonths);
void calculateAverageTemperatures(WeatherData data[], int numMonths);
void displayWeatherStatistics(WeatherData data[], int numMonths);

int main() {
    int numMonths;

    cout << "Enter the number of months (1-" << MAX_MONTHS << "): ";
    cin >> numMonths;

    if (numMonths < 1 || numMonths > MAX_MONTHS) {
        cout << "Invalid input. Please enter a number between 1 and " << MAX_MONTHS << "." << endl;
        return 1;
    }

    WeatherData yearData[MAX_MONTHS];
    inputWeatherData(yearData, numMonths);
    calculateAverageTemperatures(yearData, numMonths);
    displayWeatherStatistics(yearData, numMonths);

    return 0;
}

void inputWeatherData(WeatherData data[], int numMonths) {
    for (int i = 0; i < numMonths; ++i) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the month: ";
        getline(cin, data[i].month);

        cout << "Enter the total rainfall (in): ";
        cin >> data[i].totalRainfall;

        cout << "Enter the highest temperature (F): ";
        cin >> data[i].highTemperature;

        if (data[i].highTemperature < -100 || data[i].highTemperature > 140) {
            cout << "Invalid temperature input. Temperature must be between -100F and 140F." << endl;
            exit(1);
        }

        cout << "Enter the lowest temperature (F): ";
        cin >> data[i].lowTemperature;

        if (data[i].lowTemperature < -100 || data[i].lowTemperature > 140) {
            cout << "Invalid temperature input. Temperature must be between -100F and 140F." << endl;
            exit(1);
        }
    }
}

void calculateAverageTemperatures(WeatherData data[], int numMonths) {
    for (int i = 0; i < numMonths; ++i) {
        data[i].averageTemperature = (data[i].highTemperature + data[i].lowTemperature) / 2.0;
    }
}

void displayWeatherStatistics(WeatherData data[], int numMonths) {
    double totalRainfall = 0.0;
    double highestTemp = data[0].highTemperature;
    int highestTempMonthIndex = 0;
    double lowestTemp = data[0].lowTemperature;
    int lowestTempMonthIndex = 0;
    double avgOfAvgTemps = 0.0;

    for (int i = 0; i < numMonths; ++i) {
        totalRainfall += data[i].totalRainfall;

        if (data[i].highTemperature > highestTemp) {
            highestTemp = data[i].highTemperature;
            highestTempMonthIndex = i;
        }

        if (data[i].lowTemperature < lowestTemp) {
            lowestTemp = data[i].lowTemperature;
            lowestTempMonthIndex = i;
        }

        avgOfAvgTemps += data[i].averageTemperature;
    }

    avgOfAvgTemps /= numMonths;

    cout << "Monthly Statistics:" << endl;
    for (int i = 0; i < numMonths; ++i) {
        cout << MONTH_NAMES[i] << ": " << endl;
        cout << "  Total Rainfall: " << data[i].totalRainfall << " in." << endl;
        cout << "  High Temperature: " << data[i].highTemperature << "F" << endl;
        cout << "  Low Temperature: " << data[i].lowTemperature << "F" << endl;
        cout << "  Average Temperature: " << data[i].averageTemperature << "F" << endl;
    }

    cout << "Average monthly rainfall: " << totalRainfall / numMonths << " in." << endl;
    cout << "Total rainfall for the period: " << totalRainfall << " in." << endl;
    cout << "The highest temperature: " << highestTemp << "F occurred in " << MONTH_NAMES[highestTempMonthIndex] << endl;
    cout << "The lowest temperature : " << lowestTemp << "F occurred in " << MONTH_NAMES[lowestTempMonthIndex] << endl;
    cout << "Avg of average temps: " << avgOfAvgTemps << "F" << endl;
}