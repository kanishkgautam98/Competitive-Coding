#include<bits/stdc++.h>
using namespace std;

int solve(int a, int b)
{
  //base case
  if(b==0)
  return 1;

  //recursive ans

  int smallans = solve(a,b/2);
  smallans*=smallans;

  if(b&1)
  smallans*=a;

  return smallans;
}

int main()
{
  int a,b;
  cin>>a>>b;
  cout<<solve(a,b)<<endl;
}
