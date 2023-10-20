#include <iostream>
#include <iomanip>
#include <array>
#include <climits>
#include <cctype>
#include <cmath>
#include <limits.h>
using namespace std;

/* CODE TO PRINT MATRIX
    for (int i = 0; i < CLUE_ROWS; i++){
        for (int j = 0; j < REG_ROWS; j++){
            cout << fixed << setprecision(2) << distance[i][j] << " ";
        }
        cout << endl;
    }
*/

void calculateDistanceMatrix(double distance[][3], double clue[][2], double region[][2], const int CLUE_ROWS, const int CLUE_COLS, const int REG_ROWS, const int REG_COLS){
    double calculated_value = 0;
    for (int i = 0; i < CLUE_ROWS; i++){
        for (int j = 0; j < REG_ROWS; j++){
            distance[i][j] = sqrt(pow(clue[i][0] - region[j][0], 2) + pow(clue[i][1] - region[j][1], 2));
        }
    }
}

// DISTANCE_COLS will be 3, 

void findClueRegion(double distance[][3], int clue_regions[], const int DISTANCE_ROWS, const int DISTANCE_COLS){
    for (int i = 0; i < DISTANCE_ROWS; i++){
        int min = INT_MAX;
        for (int j = 0; j < DISTANCE_COLS; j++){
            if (distance[i][j] < min){
                min = distance[i][j];
                clue_regions[i] = j+1;
            }
        }
    }
    return;
}

void findTreasure(int clue_regions[], double region[][2], const int CLUE_REGIONS_SIZE, const int REG_ROWS, const int REG_COLS){
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    for (int i = 0; i < CLUE_REGIONS_SIZE; i++){
        if (clue_regions[i] == 1){
            counter1++;
        }
        else if (clue_regions[i] == 2){
            counter2++;
        }
        else{
            counter3++;
        }
    }
    // cout << counter1 << endl << counter2 << endl << counter3 << endl;
    if((counter1 < counter2 && counter1 < counter3) || (counter1 == counter2 && counter1 == counter3)){
        cout << "Region 1 had the least number of clues : " << counter1 << endl;
        cout << "Treasure must be buried in the coordinates ( " << region[0][0] << ", " << region[0][1] << " )" << endl;
    }
    else if ((counter2 < counter1 && counter2 < counter3) || counter2 == counter3){
        cout << "Region 2 had the least number of clues : " << counter2 << endl;
        cout << "Treasure must be buried in the coordinates ( " << region[1][0] << ", " << region[1][1] << " )" << endl;
    }
    else if (counter3 < counter1 && counter3 < counter2){
        cout << "Region 3 had the least number of clues : " << counter3 << endl;
        cout << "Treasure must be buried in the coordinates ( " << region[2][0] << ", " << region[2][1] << " )" << endl;
    }
    else if (counter1 == counter2){
        cout << "Region 1 had the least number of clues : " << counter1 << endl;
        cout << "Treasure must be buried in the coordinates ( " << region[0][0] << ", " << region[0][1] << " )" << endl;
    }
    return;
}

int main(){
    const int CLUE_ROWS = 1;
    const int CLUE_COLS = 2;
    const int REG_ROWS = 3;
    const int REG_COLS = 2;
    double clue[CLUE_ROWS][CLUE_COLS] = {{2, 10}};
    double region[REG_ROWS][REG_COLS] = {{-2, -1}, {0, 0}, {5, 8}};

    double distance[CLUE_ROWS][REG_ROWS];
    int clue_region[CLUE_ROWS];
    calculateDistanceMatrix(distance, clue, region, CLUE_ROWS, CLUE_COLS, REG_ROWS, REG_COLS);
    findClueRegion(distance, clue_region, CLUE_ROWS, REG_ROWS);
    findTreasure(clue_region, region, CLUE_ROWS, REG_ROWS, REG_COLS);

    return 0;
}