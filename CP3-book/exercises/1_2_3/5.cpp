#include <bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<int> a[n];
  for (int i = 0; i < n; i++){
    int d, m, y;
    cin >> d >> m >> y;
    a[i] = {d, m, y};
  }
  // By month
  cout << "By month" << endl;
  sort(a, a +n, [](auto const &a, auto const &b){return a[1] < b[1];});
  for (int i = 0; i < n; i++) cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << endl; 

  // By day
  sort(a, a + n);
  cout << "By day" << endl;
  for (int i = 0; i < n; i++) cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << endl; 

  // By age
  cout << "By age" << endl;
  sort(a, a + n, [](auto const &a, auto const &b){return (a[0] + a[1] * 30 + a[2] * 365) > (b[0] + b[1] * 30 + b[2] * 365);});
  for (int i = 0; i < n; i++) cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << endl; 
}