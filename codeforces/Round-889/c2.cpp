<// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void print(vector<pair<int,int>> &v){
  cout << v.size() << endl;
  for (auto x: v) cout << x.first + 1 << ' ' << x.second + 1 << endl;
}

void solve(){
  int n;
  cin >> n;
  int a[n], b[n];
  pair<ll, int> pos, neg;
  pos = neg = {0,0};
  for (int i =0 ;i < n; i++){
    cin >> a[i];
    b[i] = a[i];
    if (pos.first < a[i]){
      pos = {a[i], i};
    }
    if (neg.first > b[i]){
      neg = {b[i], i};
    }
  }
  auto copypos = pos;
  vector<pair<int,int>> c, d;
  // Pos
  if (pos.first > 0){
    // Convert pos > abs(neg)
    while (pos.first < abs(neg.first)){
      c.push_back({pos.second, pos.second});
      a[pos.second] += pos.first;
      pos.first = a[pos.second];
    }
    // All neg to pos
    for (int i = 0;i < n; i++){
      if (a[i] < 0){
        a[i] += pos.first;
        c.push_back({i, pos.second});
      } 
    }
    // Prefix sum
    for (int i = 1 ; i < n; i++){
      a[i] += a[i - 1];
      c.push_back({i, i - 1});
    }
  }

  if (neg.first < 0){
    while (abs(neg.first) < abs(copypos.first)){
      b[neg.second]  += neg.first;
      neg.first = b[neg.second];
      d.push_back({neg.second, neg.second});
    }

    for (int i = 0 ;i < n; i++){
      if (b[i] > 0){
        d.push_back({i, neg.second});
        b[i] += neg.first;
      }
    }

    for (int i = n - 2;i >= 0; i--){
      b[i] += b[i + 1];
      d.push_back({i, i + 1});
    }
  }


  // Check
  bool fc = 1, fd = 1;
  for (int i = 0 ; i < n - 1; i++){
    if (a[i] > a[i + 1]) fc &= 0;
    if (b[i] > b[i + 1]) fd &= 0;
  }

  if (fc && fd){
    if (c.size() <= d.size()) print(c);
    else print(d);
  }
  else if (fc){
    print(c);
  }
  else if (fd){
    print(d);   
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
},

>