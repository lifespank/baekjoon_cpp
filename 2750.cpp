#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arr[1001];

int partition(int* arr, int low, int high) {
    int mid = low + (high - low) / 2;
    swap(arr[low], arr[mid]);

    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j) {
        while(pivot < arr[j]) {
            j--;
        }
        while(i < j && pivot >= arr[i]) {
            i++;
        }
        swap(arr[i], arr[j]);
    }
    arr[low] = arr[i];
    arr[i] = pivot;
    return i;

}

void quickSort(int* arr, int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, N - 1);
    for(int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }


    return 0;
}