// Iterate over an array and tell how many numbers are greater than x
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, c; 
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    cin >> c;
    int queries[c];
   
    for (int i = 0; i < c; i++) cin >> queries[i];


    for (int query : queries){
        int counter = 0;
        for (int j: arr){
            if (j > query) counter += 1;
        }
        cout << counter << endl;
    }

    return 0;
}