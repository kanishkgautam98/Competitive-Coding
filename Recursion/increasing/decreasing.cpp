#include<bits/stdc++.h>
using namespace std;

void increasingorder(int n) {
    if (n == 0) {
        return;
    }

    increasingorder(n - 1);

    cout << n << endl;
    return;

}

int main() {
    int n = 5;
    increasingorder(n);
}