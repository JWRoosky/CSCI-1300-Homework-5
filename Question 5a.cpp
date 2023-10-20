#include <iostream>
#include <iomanip>
#include <array>
#include <climits>
#include <cctype>
#include <cmath>
using namespace std;

/* CODE TO PRINT MATRIX
    for (int i = 0; i < CLUE_ROWS; i++){
        for (int j = 0; j < REG_ROWS; j++){
            cout << fixed << setprecision(2) << distance[i][j] << " ";
        }
        cout << endl;
    }
*/

// CLUE_COLS will be 2, REG_ROWS will be 3, REG_COLS will be 2

void calculateDistanceMatrix(double distance[][3], double clue[][2], double region[][2], const int CLUE_ROWS, const int CLUE_COLS, const int REG_ROWS, const int REG_COLS){
    double calculated_value = 0;
    for (int i = 0; i < CLUE_ROWS; i++){
        for (int j = 0; j < REG_ROWS; j++){
            distance[i][j] = sqrt(pow(clue[i][0] - region[j][0], 2) + pow(clue[i][1] - region[j][1], 2));
        }
    }
}

int main(){
    const int CLUE_ROWS = 5;
    const int CLUE_COLS = 2;
    const int REG_ROWS = 3;
    const int REG_COLS = 2;
    double clue[CLUE_ROWS][CLUE_COLS] = {{2, 10}, {2, 5}, {8, 4}, {5, 8}, {1, 2}};
    double region[REG_ROWS][REG_COLS] = {{0, 0}, {5, -1}, {-1, -2}};


    double distance[CLUE_ROWS][REG_ROWS];
    calculateDistanceMatrix(distance, clue, region, CLUE_ROWS, CLUE_COLS, REG_ROWS, REG_COLS);
}