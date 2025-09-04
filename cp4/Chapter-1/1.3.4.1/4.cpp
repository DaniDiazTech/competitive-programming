#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<int> a(n);
  for (int i =0 ;i < n; i++)cin>>a[i];
  sort(a.begin(), a.end());
  auto it = unique(a.begin(), a.end());
  a.erase(it, a.end());
  for (auto x: a) cout << x << endl;
}