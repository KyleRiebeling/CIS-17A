#include <iostream>
#include <iomanip>
using namespace std;

/*
  Weather Stats Structure
  By: Kyle Riebeling
  On: 1/10/2024
  Description: Takes in user input for weather data foor each month in
  the year to store that data in an array of structs.
*/

struct WeatherStats{
    double Total_Rainfall;
    double Total_Snowfall;
    double High_Temperature;
    double Low_Temperature;
    double Average_Temperature;
};


int main(){
    const int MONTHS = 12;
    const int OUT_W = 22;

    double averageRain = 0, totalRain = 0;
    double averageSnow = 0, totalSnow = 0;
    double averageTemp = 0, high = 0, low = 151;

    WeatherStats year[MONTHS];
    string monthNames[MONTHS] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    //Input Loop
    for (int i = 0; i < MONTHS; i++){
        cout << "Enter the following data for " << monthNames[i] << endl;

        cout << "Total Rainfall: ";
        cin >> year[i].Total_Rainfall;

        while (year[i].Total_Rainfall < 0){
            cout << "Rainfall must be >= 0." << endl;
            cout << "Total Rainfall: ";
            cin >> year[i].Total_Rainfall;
        }

        cout << "Total Snowfall: ";
        cin >> year[i].Total_Snowfall;

        while (year[i].Total_Snowfall < 0){
            cout << "Snowfall must be >= 0." << endl;
            cout << "Total Snowfall: ";
            cin >> year[i].Total_Snowfall;
        }

        cout << "High Temperature: ";
        cin >> year[i].High_Temperature;

        while (year[i].High_Temperature < -150 || year[i].High_Temperature > 150){
            cout << "Temperatures can only be between -150 && 150." << endl;
            cout << "High Temperature: ";
            cin >> year[i].High_Temperature;
        }

        cout << "Low Temperature: ";
        cin >> year[i].Low_Temperature;

        while (year[i].Low_Temperature < -150 || year[i].Low_Temperature > 150){
            cout << "Temperatures can only be between -150 && 150." << endl;
            cout << "Low Temperature: ";
            cin >> year[i].Low_Temperature;
        }

        //Calculate average
        year[i].Average_Temperature = (year[i].High_Temperature +
                                        year[i].Low_Temperature)/2.0;
    }

    //Find averages and high and low
    for (int i = 0; i < MONTHS; i++){
        totalRain += year[i].Total_Rainfall;
        totalSnow += year[i].Total_Snowfall;
        //Add togther here, then divide after since total isnt needed
        averageTemp += year[i].Average_Temperature;

        if (year[i].High_Temperature > high) high = year[i].High_Temperature;
        if (year[i].Low_Temperature < low) low = year[i].Low_Temperature;
    }
    averageRain = totalRain / 12.0;
    averageSnow = totalSnow / 12.0;
    averageTemp /= 12.0;

    //Display averages And totals
    //Clean previous input mess so only table shows
    system("cls");

    cout << "\tYearly Stats" << endl;

    cout << setw(OUT_W) << left << "Total Rain: " << totalRain << endl;
    cout << setw(OUT_W) << left << "Average Rain: " << averageRain << endl;

    cout << setw(OUT_W) << left << "Total Snow: " << totalSnow << endl;
    cout << setw(OUT_W) << left << "Average Snow: " << averageSnow << endl;

    cout << setw(OUT_W) << left << "Average Temperature: " << averageTemp << endl;

    //Display high and months occured in
    cout << setw(OUT_W) << left << "Highest Temp: " << high << " during ";
    for (int i = 0; i < MONTHS; i++){
        if (year[i].High_Temperature == high) cout << monthNames[i] << " ";
    }
    cout << endl;

    //Display low and months occured in
    cout << setw(OUT_W) << left << "Lowest Temp: " << low << " during ";
    for (int i = 0; i < MONTHS; i++){
        if (year[i].Low_Temperature == low) cout << monthNames[i] << " ";
    }
    cout << endl << endl;


    return 0;
}