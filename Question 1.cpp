#include <iostream>
#include <array>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string card_names[9] = {"Ace", "Clubs", "Diamonds", "Hearts", "Spades", "Jack", "Queen", "King", "Joker"};
    double sq_root_nums[10] = {};
    int numbers[7] = {};
    char letters[52] = {};

    for (int i = 0; i < 9; i++){
        cout << card_names[i] << endl;
    }

    for (int i = 1; i <= 10; i++){
        sq_root_nums[i-1] = sqrt((double)i);
    }

    for (int i = 0; i < (end(sq_root_nums) - begin(sq_root_nums)); i++){
        cout << fixed << setprecision(3) << sq_root_nums[i] << endl;
    }

    int index = 0;

    for (int i = 50; i<=100; i++){
        if (i % 7 == 0){
            numbers[index] = i;
            index ++;
        }
    }

    for (int i = 0; i < 7; i++){
        cout << numbers[i] << endl;
    }

    int lower_index = 0;
    int upper_index = lower_index + 1;

    for (int i = 65; i <= 90; i ++){
        letters[upper_index] = (char)(i + 32);
        letters[lower_index] = (char)(i);
        upper_index += 2;
        lower_index += 2;
    }

    for (int i = 0; i < 52; i++){
        cout << letters[i] << endl;
    }
    return 0;
}