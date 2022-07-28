/*
Problem name: Watermelon
Algorithm or Logic: Simple if
Complexity: O(1)
Link: https://codeforces.com/problemset/problem/4/A
More info: 
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n;
    cin >> n;
    if (n % 2 == 0 && n >= 4){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}
