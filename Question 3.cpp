#include <iostream>
using namespace std;

void mostPopularWord(string words[], const int WORD_SIZE){

    int max_frequency = 1;
    int most_recent = 1;
    string most_common_string = "";

    if (WORD_SIZE == 1){
        cout << "The most popular word : " << words[0] << endl;
        cout << "Frequency : " << 1 << endl;
        cout << "Found at pos : " << endl;
        cout << 0;
    }
    else{
        for (int i = 0; i < WORD_SIZE; i++){
            int current_frequency = 1;
            int current_index = i;

            for (int j = i + 1; j < WORD_SIZE; j++){
                if(words[j] == words[i]){
                    current_frequency++;
                    current_index = j;
                }
            }

            if(current_index > most_recent){
                most_recent = current_index;
            }

            if (current_frequency > max_frequency || ((current_frequency == max_frequency) && current_index >= most_recent)){
                max_frequency = current_frequency;
                most_common_string = words[i];
            }
        }


        cout << "The most popular word : " << most_common_string << endl;
        cout << "Frequency : " << max_frequency << endl;
        cout << "Found at pos : " << endl;
        for (int i = 0; i < WORD_SIZE; i++){
            if (words[i] == most_common_string){
                cout << i << endl;
            }
        }
    }
}

int main(){
    const int WORDS_SIZE = 6;
    string words[WORDS_SIZE] = {"amazon", "amazon", "amazon", "google", "google", "google"};
    mostPopularWord(words, WORDS_SIZE);
    return 0;
}