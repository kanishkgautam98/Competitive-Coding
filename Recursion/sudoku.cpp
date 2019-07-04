#include<bits/stdc++.h>

using namespace std;

bool issafe(int **sudoku, int i, int j, int n, int number) {
    for (int temp = 0; temp < n; temp++) {
        if (sudoku[i][temp] == number || sudoku[temp][j] == number) {
            return false;
        }
    }

    int rowstartindex = (i / 3) * 3;
    int columnstartindex = (j / 3) * 3;

    for (; rowstartindex < rowstartindex + 3; rowstartindex++) {
        for (; columnstartindex < columnstartindex + 3; columnstartindex++) {
            if (sudoku[rowstartindex][columnstartindex] == number) {
                return false;
            }
        }
    }
    return true;
}


bool sudokusolver(int **sudoku, int i, int j, int n) {
    if (i == n) {
        return true;
    }

    if (j == n) {
        return sudokusolver(sudoku, i + 1, 0, n);
    }

    if (sudoku[i][j] != 0) {
        sudokusolver(sudoku, i, j + 1, n);
    }

    for (int number = 1; number <= n; number++) {
        if (issafe(sudoku, i, j, n, number)) {
            sudoku[i][j] = number;
            bool temp = sudokusolver(sudoku, i, j + 1, n);
            if (temp) {
                return true;
            }
            sudoku[i][j] = 0;
        }
    }
    return false;
}

int main() {
    int **sudoku = new int *[9];

    for (int i = 0; i < 9; i++) {
        sudoku[i] = new int[9];
        for(int j = 0 ; j <9 ;j++){
            cin>>sudoku[i][j];
        }
    }

    if (sudokusolver(sudoku, 0, 0, 9)) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }

    }


}