/*
Problem name:  Functions
Algorithm or Logic:
Complexity: 
Link: https://www.hackerrank.com/challenges/c-tutorial-functions/
More info: 
*/

#include <iostream>
#include <cstdio>
using namespace std;

/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int  max_of_four(int a, int b,int c,int d){
    int arr[4] = {a, b, c, d};
    long long int mx = -10e9;
    for (int i: arr){
        if (i > mx){
            mx = i;
        }
    }
    return mx;
}
int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
