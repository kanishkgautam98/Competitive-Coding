#include<bits/stdc++.h>

using namespace std;

int fib(int n, int *memo) {
    if (n == 0 || n == 1) {
        return 1;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];


}

int main() {
    int n;
    cin >> n;
    int *memo = new int[n+1];
    for(int i = 0; i < n+1; i++){
        memo[i] = -1;
    }
    cout << fib(n, memo) << endl;

}