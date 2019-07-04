#include<bits/stdc++.h>
using namespace std;

int lis(int * arr, int n) {
    int * dp = new int [n];

    fill(dp,dp+n,1);
    for(int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }


    for(int i = 0; i < n; i++) {
        for(int j = i - 1; j>=0 ; j--){
            int temp;
            if(arr[j] <= arr[i]) {
                temp = dp[j] + 1;
            }
            dp[i] = max(temp,dp[i]);
        }
    }

    int ans = dp[n-1];

    for(int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }

    delete [] dp;

    return ans;
}

int main() {
    int n;
    cin >> n;
    int * arr = new int [n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << lis(arr,n) << endl;
}