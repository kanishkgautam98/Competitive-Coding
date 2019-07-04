#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll  func(int i, int j,int * a, int *b,int **dp,int n,int m) {
    if(i==n){
        //ALL BOYS ARE USED
        return 0;
    }

    if(j==m){
        //ALL GIRLS ARE USED BUT BOYS ARE LEFT WHICH IS NOT A VALID CASE SO WE RETURN INT_MAX
        return 100000000;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int op1 = abs(a[i]-b[j])+func(i+1,j+1,a,b,dp,n,m);
    int op2 = func(i,j+1,a,b,dp,n,m);
//     cout<<a[i]<<" "<<abs(a[i]-b[j])<<" "<<b[j]<<"at index"<<i<<j<<endl;

    dp[i][j] = min(op1,op2);

    return min(op1,op2);



}

int main() {

    int n,m;
    cin >> n >> m;
    int * a = new int [n];
    int * b = new int [m];

    int **dp = new int *[n];
    for(int i = 0; i < n; i++) {
        dp[i] = new int [m];
        fill(dp[i],dp[i]+m,-1);
    }


//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < m; j++) {
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a,a+n);
    sort(b,b+m);

//        for(int i=0;i<n;i++){
//            cout<<a[i]<<" ";
//        }
//        cout<<endl;
//
//        for(int j=0;j<m;j++){
//            cout<<b[j]<<" ";
//        }

    ll ans = func(0,0,a,b,dp,n,m);
    cout << ans << endl;

//        for(int i = 0; i < n; i++){
//            for(int j = 0; j < m; j++) {
//                cout<<dp[i][j]<<" ";
//            }
//            cout<<endl;
//        }

    delete[]a;
    delete[]b;
    for(int i = 0; i < n; i++) {
        delete[]dp[i];
    }
    delete[]dp;


}