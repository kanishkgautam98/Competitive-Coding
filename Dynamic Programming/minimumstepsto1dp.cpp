#include<bits/stdc++.h>

using namespace std;

int min(int n) {
    int *a = new int[n + 1];

    fill(a, a + n + 1, INT_MAX);

    a[0] = 0, a[1] = 0, a[2] = 1, a[3] = 1;

    for (int i = 4; i < n + 1; i++) {
        int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX, ans4 = INT_MAX;
        if (i % 3 == 0) {
            ans1 = a[i / 3] + 1;
        }
        if (i % 2 == 0) {
            ans2 = a[i / 2] + 1;
        }
        ans3 = a[i - 1] + 1;

        a[i] = min(ans1, min(ans2, ans3));

    }
    return a[n];
}

int main() {
    int n;
    cin >> n;
    cout << min(n) << endl;
}