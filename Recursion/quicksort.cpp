#include<bits/stdc++.h>

using namespace std;


int partition(int *array, int start, int end) {
    int i = start - 1;
    int j = start;
    int pivot = array[end];

    for (; j < end; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }

    //Bring pivot element in the sorted position
    swap(array[i + 1], array[end]);

    return i + 1;

}

void quicksort(int *array, int start, int end) {
    if (start >= end) {
        return;
    }

    int pivot = partition(array, start, end);

    quicksort(array, start, pivot - 1);
    quicksort(array, pivot + 1, end);
    return;
}

int main() {

    int n;
    cin >> n;
    int *array = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    quicksort(array, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if(i != n-1)
        cout << array[i] << " ";
        else
            cout << array[i] << endl;
    }

}