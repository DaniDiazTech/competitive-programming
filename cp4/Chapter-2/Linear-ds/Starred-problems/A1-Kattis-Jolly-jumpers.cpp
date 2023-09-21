#include <bits/stdc++.h>
using namespace std;
int main(){
  #if LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int n;
  bool l =0;
  while (cin >> n){
    if (l) cout << endl;
    l = 1;
    int a[n];
    int b[n - 1];
    bool f= 1;
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    for (int i = 1; i < n; i++){
      b[i - 1] = abs(a[i] - a[i - 1]);
    }
    sort(b, b + n - 1);
    for (int i = 1; i <= n - 1; i++){
      f &= b[i - 1] == i;
    }
    cout << (f ? "Jolly": "Not jolly");
  }
}