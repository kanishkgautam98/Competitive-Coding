#include<bits/stdc++.h>

using namespace std;


int minimumCostToEnd(int **b, int n) {

    for (int i = 1; i < n; i++) {
        b[0][i] = b[0][i - 1] + b[0][i];
        b[i][0] = b[i - 1][0] + b[i][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            b[i][j] = min(b[i - 1][j], b[i][j - 1]) + b[i][j];
        }
    }

    return b[n - 1][n - 1];
}

int main() {
    int n;
    cin >> n;
    int **b = new int *[n];

    for (int i = 0; i < n; i++) {
        b[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }

    cout << minimumCostToEnd(b, n) << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] <<" ";
        }
        cout<<endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] b[i];
    }
    delete[] b;
}