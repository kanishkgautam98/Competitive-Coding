#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

void towerOfHanoi ( int n, char src, char dest, char helper) {
    // Base case
    if (n==0) {
        return;
    }

    //Recursive case
    //First move n-1 disks from rc to helper
    towerOfHanoi(n-1,src,helper,dest);

    cout<<"Move "<<n<<" disk from "<<src<<" to "<<dest<<endl;

    towerOfHanoi(n-1,helper,dest,src);


}
int main(){

    int n;
    cin>>n;
    towerOfHanoi(n,'A','C','B');
    return 0;
}