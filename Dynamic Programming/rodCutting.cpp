#include<bits/stdc++.h>
using namespace std;

int maxprofit(int * a, int n) {

    if(n==0) return 0;

    int ans = INT_MIN;

    for(int i = 1; i <= n; i++){
        int temp = a[i] + maxprofit(a,n-i);
        ans = max(temp,ans);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    int * a = new int [n+1];

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = maxprofit(a, n);

    cout << ans << endl;

    delete [] a;


}