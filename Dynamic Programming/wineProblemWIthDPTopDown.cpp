#include <bits/stdc++.h>

using namespace std;


int maxprofit(int *a, int **b, int si, int ei, int year) {

    if (si > ei) {
        return 0;
    }

    if (b[si][ei] != -1) return b[si][ei];

    int ans1 = a[si] * year + maxprofit(a, b, si + 1, ei, year + 1);
    int ans2 = a[ei] * year + maxprofit(a, b, si, ei - 1, year + 1);

    int ans = max(ans1, ans2);

    b[si][ei] = ans;
    return ans;


}

int main() {
    int n;
    cin >> n;
    int * a = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int **b = new int *[n];

    for (int i = 0; i < n; i++) {
        b[i] = new int[n];
        for (int j = 0; j < n; j++) {
            b[i][j] = -1;
        }
    }


    cout << maxprofit(a, b, 0, n - 1, 1) << endl;

    for (int i = 0; i < n; i++) {
        delete[] b[i];
    }
    delete[]a;
    delete[]b;

}