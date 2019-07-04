#include<bits/stdc++.h>

using namespace std;

int maxprofit(int *input, int *memo, int length) {
    if (length <= 0) return 0;
    if (memo[length] != -1) return memo[length];
    int ans = INT_MIN;

    for (int i = 1; i <= length; i++) {
        int temp = input[i] + maxprofit(input, memo, length - i);
        ans = max(temp, ans);
    }

    memo[length] = ans;

    return ans;

}

int maxprofit2(int * input, int length) {
    if(length == 0) return 0;

    int * memo = new int [length+1];
    fill(memo,memo+length+1,0);

    for(int i = 1; i<=length ; i++){
        int temp = 0;
        for(int j = 1; j<=i ;j++){
            int temp2 = input[j] + memo[i-j];
            temp = max(temp,temp2);
        }
        memo[i] = temp;
    }

    int ans = memo[length];
    delete [] memo;
    return ans;


}


int main() {
    int length;
    cin >> length;
    int *input = new int[length+1];
    int *memo = new int[length+1];
    fill(memo, memo + length+1, -1);

    for (int i = 1; i <= length; i++) {
        cin >> input[i];
    }

    for(int i = 1; i<=length ; i++){
        cout << memo[i] <<" ";
    }

    int ans = maxprofit(input, memo, length);
    int ans1 = maxprofit2(input,length);
    cout << ans <<" "<< ans1 << endl;
    delete[] input;
    delete[] memo;
}