#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1000];
int LIS[1000];
int rLIS[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        LIS[i] = 1;
        if(i > 0) {
            for(int j = 0; j < i; j++) {
                if(arr[i] > arr[j] && LIS[i] < LIS[j] + 1) {
                    LIS[i] = LIS[j] + 1;
                }
            }
        }
    }
    rLIS[N - 1] = 1;
    for(int i = N - 2; i >= 0; i--) {
        rLIS[i] = 1;
        for(int j = N - 1; j > i; j--) {
            if(arr[i] > arr[j] && rLIS[i] < rLIS[j] + 1) {
                rLIS[i] = rLIS[j] + 1;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        LIS[i] += rLIS[i];
    }
    cout << *max_element(LIS, LIS + N) - 1;


    return 0;
}