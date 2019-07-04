#include<bits/stdc++.h>

using namespace std;

int lcs (string x, string y) {
    int len1 = x.size();
    int len2 = y.size();

    int **dp = new int *[len1+1];
    for(int i = 0; i < len1+1; i++) {
        dp[i] = new int [len2+1];
        fill(dp[i],dp[i]+len2+1,0);
    }

    for(int i = 1; i <= len1; i++) {
        for( int j = 1; j <= len2; j++) {
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int ans = dp[len1][len2];
    cout <<  ans << endl;

    for(int i = 0; i < len1+1; i++) {
        delete[]dp[i];
    }
    delete[]dp;
    return ans;

}

int main() {
    string x;
    string y;

    getline(cin, x);
    getline(cin, y);

    int ans = lcs(x, y);

    cout << ans << endl;
}