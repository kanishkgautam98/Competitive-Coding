#include<bits/stdc++.h>

using namespace std;

int maxprofit(int *arr, int be, int en, int year) {
    if (be > en) {
        return 0;
    }

    int q1 = arr[be] * year + maxprofit(arr, be + 1, en, year + 1);
    int q2 = arr[en] * year + maxprofit(arr, be, en - 1, year + 1);
    int ans = max(q1, q2);
    return ans;
}

int main() {
    int arr[100];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = maxprofit(arr, 0, n - 1, 1);
    cout << ans << endl;

}