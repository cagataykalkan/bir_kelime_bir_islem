//
//  main.cpp
//  yazilim_yapimi_bir_kelime_bir_islem
//
//  Created by Çağatay KALKAN on 28.04.2023.
//


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <time.h>

using namespace std;


//functions called
void numberCreator(vector<double>& numbers, int& target);

void calculate(vector<double>& numbers, int target, vector<string>& answers, vector<int>& sign, vector<string>& signString, int& counter);


int main() {
    
    //variables created
    
    vector<string> answers;
    vector<string> signString = {" + ", " - ", " / ", " * "};
    int counter = 0;
    int target;
    
    
    while(true) {
        vector<double> numbers;
        vector<int> sign;
        numberCreator(numbers, target);
        
        do {
            calculate(numbers, target, answers, sign, signString, counter);
        } while(next_permutation(numbers.begin(), numbers.end()));
        counter = 0;
        
        cout << "\t\tAll answers listed.\n\n";
        cout << "\t\tIf you can't see any answer there is no solution with these numbers.\n\n";
        cout << "\t\tIf you want to try with other numbers press --> \"ENTER\" <--\n";
        cout << "\n\t|--------------------------------------------------------|\n\n";
        
        //program waits for user to continue with "getchar()" operator
        
        getchar();
        getchar();
    }
    return 0;
}

//this function calculates all possibilitys

void calculate(vector<double>& numbers, int target, vector<string>& answers, vector<int>& sign, vector<string>& signString, int& counter) {
    
    if(sign.size() + 1 < numbers.size()) {
        for(int i = 0; i < 4; i++) {
            sign.push_back(i);
            calculate(numbers, target, answers, sign, signString, counter);
            sign.pop_back();
    }
                return;
    }
    double temp = numbers[0];
    for(int i = 0; i < sign.size(); i++) {
        switch(sign[i]) {
            case 0:
                temp += numbers[i+1];
                break;
            case 1:
                temp -= numbers[i+1];
                break;
            case 2:
                temp *= numbers[i+1];
                break;
            case 3:
                if(numbers[i+1] == 0) return;
                temp /= numbers[i+1];
                break;
        }
    }
    if(abs(temp - target) < .00000000001) {
        string cozum = std::to_string((int)numbers[0]);

        for(int i = 0; i < sign.size(); i++){
            cozum += signString[sign[i]];
            cozum += std::to_string((int)numbers[i+1]);
        }

        if (std::find(answers.begin(), answers.end(), cozum) == answers.end()) {
            answers.push_back(cozum);
            counter++;
            cout << "\t\t" << counter << ". solution  " << cozum << " = " << target << endl << endl;
        }
    }
}

//this function creates random numbers and main page

void numberCreator(vector<double>& numbers, int& target){
    //srand(time(NULL));
    cout << "\n\t|----------------- WELCOME TO HOME PAGE -----------------|" << endl;
    for(int i = 0; i < 5; i++){
        int x;
        x = rand() % 9 + 1;
        cout <<"\n\t\t"<< i + 1 << ". number =\t" << x << endl;
        numbers.push_back((double)x);
    }
    int x = (rand() % 9 + 1) * 10;
    cout << "\n\t\tEven numbers that are multiples of 10 : " << x <<endl;
    numbers.push_back((double)x);
    cout << "\n\t\tEnter 3 digit target number :  ";
    cin >> target;
    sort(numbers.begin(), numbers.end());
    cout << "\n\t|--------------------------------------------------------|\n\n";
}


