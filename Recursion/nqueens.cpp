#include<bits/stdc++.h>
using namespace std;

bool issafe(int board[][10],int i, int j)
{
  for(int row=0;row<=i;i++)
  {
    if(board[row][j]==1)
    return false;
  }

  int row = i;
  int col = j;

  while(row>=0 && col >=0)
  {
    if(board[row][col]==1)
    {return false;}
    row--;
    col--;
  }

  int row2 = i;
  int col2 = j;

  while(row>=0 && col<n)
  {
    if(board[row][col]==1)
    {return false;}
    row--;
    col--;
  }
  return true;
}

bool nqueen(int board[][10],int row,int n)
{
  if(i==n)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(board[i][j]==0)
        cout<<0<<endl;
        else
        cout<<1<<endl;
      }
    }
    return true;}

  for(int i=0;i<n;i++)
  {
    if(issafe(board,row,i))
    {
      board[row][i]=1;
      bool nextqueen = nqueen(board,row+1,n);
      if(nextqueen)
      return true;
       board[row][i]=0;
    }
  }
  return false;

}
int main()
{


  return 0;
}
