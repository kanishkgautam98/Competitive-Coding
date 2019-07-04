#include<bits/stdc++.h>
using namespace std;

int editDistance(string x, string y) {
    int len1 = x.length();
    int len2 = y.length();

    int **dp = new int * [len1+1];

    for(int i = 0; i <= len1; i++) {
        dp[i] = new int [len2+1];
    }

    for(int i = 0; i<=len1 ;i++) {
        dp[i][0] = i;
    }

    for(int j = 0; j<=len2; j++) {
        dp[0][j] = j;
    }

    for(int i = 1; i <= len1; i++) {
        for( int j=1; j<= len2; j++) {
            if(x[i-1]==y[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
            }
        }
    }

    int ans = dp[len1][len2];

    for(int i = 0; i < len1; i++) {
        delete [] dp [i];
    }
    delete [] dp;

    return ans;
}

int main() {
    string x,y;
    getline(cin,x);
    getline(cin,y);

    cout << editDistance(x,y) << endl;
}