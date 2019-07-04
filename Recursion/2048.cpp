#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;



void printfunc( int input) {
    if (input == 0) {
        return;
    }

    unordered_map<int,string> mapp;

    mapp[0] = "ZERO";
    mapp[1] = "ONE";
    mapp[3] = "THREE";
    mapp[4] = "FOUR";
    mapp[5] = "FIVE";
    mapp[2] = "TWO";

    printfunc(input/10);
    cout<<mapp[input%10]<<endl;
}
int main () {
    int input;
    cin >> input;
    printfunc(input);
}
