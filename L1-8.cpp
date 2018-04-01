// L1-8 猜数字
// Language: C++

#include <iostream>
#include <climits>

using namespace std;

struct Player{
    string name;
    int guess;
};

double abs(double a){
    return a < 0 ? -a : a;
}

int main(){
    int player_count;
    cin >> player_count;

    Player players[player_count];
    int sum = 0;
    for(int i = 0;i < player_count;i++){
        cin >> players[i].name >> players[i].guess;
        sum += players[i].guess;
    }
    double average = sum / (double)player_count;
    average /= 2;

    int min_index, min_difference = INT_MAX;
    for(int i = 0;i < player_count;i++){
        if(abs(players[i].guess - average) < min_difference){
            min_index = i;
            min_difference = abs(players[i].guess - average);
        }
    }

    cout << (int)average << " " << players[min_index].name;

    return 0;
}
