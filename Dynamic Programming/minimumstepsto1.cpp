#include<bits/stdc++.h>

using namespace std;

int minsteps(int n, int *arr) {
    if (n <= 1) {
        return 0;
    }

    int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;

    if (n % 3 == 0) {
        ans1 = minsteps(n / 3, arr) + 1;
    }

    if (n % 2 == 0) {
        ans2 = minsteps(n / 2, arr) + 1;
    }

    ans3 = minsteps(n - 1, arr) + 1;

    return min(ans1, min(ans2, ans3));

}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    fill(arr, arr + n, -1);

    cout << minsteps(n, arr) << endl;
}