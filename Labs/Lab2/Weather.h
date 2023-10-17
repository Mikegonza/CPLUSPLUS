/*---Miguel Angel Gonzalez Mauricio
  ---Programming Fundamentals II
  ---COSC-1437
  ---Instructor: Brian Koontz
  */
#include <string>
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