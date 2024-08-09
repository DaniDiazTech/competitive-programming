// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  vector<ll> a(n), b(n);

  pair<ll, int> pos, neg;
  pos = neg = {0, 0};
  for (int i = 0; i < n; i++){
    cin >> a[i];
    b[i] = a[i];
    if (pos.first < a[i]){
      pos = {a[i], i};
    }
    if (neg.first > a[i]){
      neg = {a[i], i};
    }
  }

  vector<pair<int,int>> c, d;

  // Pos
  if (pos.first > 0){
    for (int i = 0;i < n - 1; i++){
      if (a[i] <= a[i + 1]) continue;
      while (a[i] > a[i  + 1]){
        a[i + 1] += pos.first;
        c.push_back({i + 1, pos.second});
      }
      if (pos.first < a[i + 1]){
        pos = {a[i + 1], i + 1};
      }
    }
  }
  
  if (neg.first < 0){
    for (int i = n - 1; i >= 1; i--){
      if (b[i - 1]  <= b[i]) continue;
      while (b[i - 1] > b[i]){
        b[i - 1] += neg.first;
        d.push_back({i - 1, neg.second});
      }
      if (neg.first > b[i - 1]){
        neg = {b[i - 1], i - 1};
      }
    }
  }

  // Check
  bool fc = 1, fd = 1;
  for (int i = 0 ; i < n - 1; i++){
    if (a[i] > a[i + 1]) fc &= 0;
    if (b[i] > b[i + 1]) fd &= 0;
  }


  if (fc && fd){
    cout << min(c.size(), d.size()) << '\n';
    if (c.size() <= d.size()){
      for (auto x: c) cout << x.first + 1 << " " << x.second  + 1<< '\n';
    }
    else{
      for (auto x: d) cout << x.first  + 1<< " " << x.second + 1 << '\n';
    }
  }
  else if (fc){
    cout << c.size() << '\n';
    for (auto x: c) cout << x.first + 1 << " " << x.second  + 1<< '\n';
  }
  else if (fd){
    cout << d.size() << '\n';
    for (auto x: d) cout << x.first + 1 << " " << x.second + 1 << '\n';
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}