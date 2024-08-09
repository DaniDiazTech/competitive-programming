// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> a(m + 1);

  // 1 -> first, 2->second
  vector<int> al(n), f(n), s(n);

  for (int i = 0;i < n; i++){
    cin >> f[i];
    cin >> s[i];
  }
  // first round 
  for (int i =0 ;i < n; i++){
    // Go for first
    if (a[f[i]] < c){
      al[i] = 1;
      a[f[i]]++;
    }
    else{
      // second option
      if (a[s[i]] < c){
        al[i] = 2;
        a[s[i]]++;
      }
    }
  }
  
  int x,y;
  x = y = 0;
  for (int i = 0; i < n; i++){
    x += al[i] == 1;
    y += al[i] == 2;
  }

  cout << x << " " << y << endl;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
