#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007;

int ways (int **matrix, int m, int n) {
    if (m==0 && n==0) {
        return 0;
    }

    int **dp = new int *[m];

    for (int i = 0 ; i < m; i++) {
        dp[i] = new int [n];
        fill(dp[i],dp[i]+n,0);
    }

    for (int i = 0; i < m; i++) {
        if(matrix[i][0] == -1) {
            break;
        }
        dp[i][0] = 1;
    }

    for (int i = 0; i < n; i++) {
        if(matrix[0][i] == -1) {
            break;
        }
        dp[0][i] = 1;
    }


    for (int i = 1; i < m ; i++) {
        for (int j = 1; j < n; j++) {

            if (matrix[i][j] == -1) {
                continue;
            }
            if(matrix[i-1][j] != -1) {
                dp[i][j] = dp[i-1][j]%mod;
            }
            if(matrix[i][j-1] != -1) {
                dp[i][j] = (dp[i][j-1] + dp[i][j])%mod;
            }

        }
    }

    if(matrix[m-1][n-1] == -1) {
        return 0;
    }
    int ans = dp[m-1][n-1];

//    for(int i =0;i<m;i++) {
//        for (int j=0;j<n;j++) {
//            cout<<dp[i][j] << " ";
//        }
//        cout << endl;
//    }

    for (int i = 0; i < m; i++) {
        delete [] dp[i];
    }
    delete [] dp;

    return ans;






}


int main() {
    int m,n,p;
    cin >> m >> n >> p;

    int **matrix = new int*[m];
    for(int i = 0; i < m; i++) {
        matrix[i] = new int [n];
        fill(matrix[i],matrix[i]+n,0);
    }

    for (int i = 0; i < p; i++) {
        int x,y;
        cin >> x >> y;
        matrix[x-1][y-1] = -1;
    }

    cout << ways(matrix,m,n) << "\n";

    for (int i = 0; i < m; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
}