#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 1000003


ll n,x;
ll dp[105][3][105];

ll ways (ll i, ll prev, ll count) {

    if(i==n) {
        if (count == x) {
            return 1;
        }
        return 0;
    }

    if(dp[i][prev][count] != -1) {
        return dp[i][prev][count];
    }

    ll ans = 0;

    if(prev == 1) {
        ans = ans + ways(i+1,1,count+1);
    }
    else {
        ans = ans + ways(i+1,1,count);
    }

    ans %= mod;

    ans += ways(i+1,0,count);

    ans %= mod;

    dp[i][prev][count] = ans;

    return ans;




}





int main() {
    ll t;
    cin >> t;
    while (t--) {
        memset(dp,-1, sizeof(dp));
        cin >> n >> x;
        cout << (ways(1,1,0)+ways(1,0,0))%mod << endl;
    }


}