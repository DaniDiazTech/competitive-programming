#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, y, dl, dr; 
    cin >> n >> x >> y;
    
    if (x > y){
        dl = x - y;
        dr = n - x + y;
        cout << min(dl, dr) << endl;
    }
    else{
        dl = x + n - y;
        dr = y - x;
        cout << min(dl, dr) << endl;
    }

    return 0;
}
