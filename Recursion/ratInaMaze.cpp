//
// Created by Kanishk Gautam on 2019-05-07.
//
#include<bits/stdc++.h>

using namespace std;

bool helper(int **board, int n, int m, int **solution, int i, int j) {
    if (i == n - 1 && j == m - 1) {
        solution[i][j]=1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    if (board[i][j] == 0)
        return false;

    solution[i][j] = 1;
//    bool path1 = false, path2 = false, path3 = false, path4 = false;

    if (solution[i + 1][j] == 0 && board[i+1][j] == 1 && helper(board, n, m, solution, i + 1, j))
        return true;
    if (solution[i][j + 1] == 0 && board[i][j+1] == 1 && helper(board, n, m, solution, i, j + 1))
        return true;
    if (solution[i - 1][j] == 0 && board[i-1][j] == 1 && helper(board, n, m, solution, i - 1, j))
        return true;
    if (solution[i][j + 1] == 0 && board[i][j+1] == 1 && helper(board, n, m, solution, i, j + 1))
        return true;

    solution[i][j] = 0;
    return false;
}

void ratInamaze(int **board, int n, int m) {
    int **solution = new int *[n];

    for (int i = 0; i < n; i++) {
        solution[i] = new int[m];
        for (int j = 0; j < m; j++) {
            solution[i][j] = 0;
        }
    }

    helper(board, n, m, solution,0,0);

}

int main() {
    int n, m;
    cin >> n >> m;
    int **a = new int *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    ratInamaze(a, n, m);
}

