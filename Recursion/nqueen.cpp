//
// Created by Kanishk Gautam on 2019-05-07.
//
#include<bits/stdc++.h>

using namespace std;

bool issafe(int board[][10], int i, int j, int n) {

    for (int row = 0; row < i; row++) {
        if (board[row][j] == 1) {
            return false;
        }
    }

    // check for left diagonal
    int x = i, y = j;
    while (x >= 0 && y >= 0) {
        if (board[x--][y--])
            return false;
    }

    //check for right diagonal

     x = i, y = j;

    while (x >= 0 && y < n) {
        if (board[x--][y++])
            return false;
    }
    return true;
}

bool solvenqueen(int board[][10], int i, int n) {
    if (i == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    for( int j = 0; j < n; j++){
        if(issafe(board,i,j,n)) {
            board[i][j] = 1;
            bool nextqueen = solvenqueen(board,i+1,n);
            if(nextqueen){
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    int board[10][10] = {0};

    solvenqueen(board, 0, n);
}
