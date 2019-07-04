//
// Created by Kanishk Gautam on 2019-05-06.
//

#include<bits/stdc++.h>
using namespace std;

void permute(string input, int i) {
    if (i == input.size()) {
        cout << input << endl;
        return;
    }

    for (int j = i; j < input.size(); j++) {
        swap(input[i], input[j]);
        permute(input, i + 1);
        swap(input[i], input[j]);
    }
}

int main() {
    string input;
    getline(cin, input);
    permute(input, 0);
    return 0;
}

