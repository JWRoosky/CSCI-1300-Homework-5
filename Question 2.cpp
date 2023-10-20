#include <iostream>
#include <array>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

double temperatureMean(double new_temperature[], const int TEMP_SIZE){
    double mean = 0;
    double sum = 0;
    for (int i = 0; i < TEMP_SIZE; i++){
        sum += new_temperature[i];
    }
    mean = sum / TEMP_SIZE; 

    return mean;
}

double temperatureRange(double new_temperature[], const int TEMP_SIZE){
    double max = new_temperature[0];
    double min = new_temperature[0];
    for (int i = 1; i < TEMP_SIZE; i++){
        if (new_temperature[i] > max){
            max = new_temperature[i];
        }
        if (new_temperature[i] < min){
            min = new_temperature[i];
        }
    }
    return max - min;
}

void temperatureDelta(double new_temperature[], double old_temperature[], double delta[], const int TEMP_SIZE){
    for (int i = 0; i < TEMP_SIZE; i++){
        delta[i] = old_temperature[i] - new_temperature[i];
    }
}