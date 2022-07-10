#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, maxa, segmenta, minh, area; 
    cin >> n;
    int heights[n]; 
    for (int i = 0; i < n; i++) cin >> heights[i];

    maxa = 0;
    // base
    for (int i = 0; i < n; i++){
        // heights
        segmenta = 0;
        minh = pow(10, 5) + 1;
        for (int j = i; j < n; j++){
            minh = min(minh, heights[j]);
            area = ((j - i) + 1) * minh;
            if (area > segmenta) segmenta = area;
        }
        if (segmenta > maxa) maxa = segmenta;
    }
    cout << maxa;

    return 0;
}