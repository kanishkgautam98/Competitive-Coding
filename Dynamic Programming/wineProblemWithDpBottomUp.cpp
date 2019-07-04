#include<bits/stdc++.h>

using namespace std;
//Code may not work
int maxprofit(int *a, int n) {

    int **dp = new int *[n];

    for (int i = 0; i < n; i++) {
        dp[i] = new int[n];
        fill(dp[i], dp[i] + n, -1);
    }
    int year = n;

    for (int i = 0; i < n; i++) {
        dp[i][i] = n * a[i];

    }
    year--;

    for (int len = 2; len <= n ; len++) {
        int start = 0;
        int end = n - len -1;
        when(start<=end) {
            dp[start][end] = max(arr[start]*year+dp[start+1][end],arr[end]*year+dp[start][end-1]);
            start++;
        }
        year--;
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<b[i][j]<<" ";
        }
    }
    int ans = b[0][n-1];


    for (int i = 0; i < n; i++) {
        delete[] b[i];
    }

    delete[] b;

    return ans;

}

int main() {
    int n;
    cin >> n;

    int *a = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << maxprofit(a, n);
    delete[] a;

}