#include<bits/stdc++.h>
using namespace std;

long fastpower(int n, int power) {
    if (power == 0) {
        return 1;
    }
    int tempans = fastpower(n, power / 2);

    tempans *= tempans;

    if (power & 1) {
        return tempans * tempans;
    }

    return tempasn;
}

int main() {
    int input;
    cin >> input;
    int power;
    cin >> power;
    cout << fastpower(n, power) << endl;
}