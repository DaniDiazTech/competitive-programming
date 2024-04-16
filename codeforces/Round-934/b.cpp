// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n+ 1), b(n + 1);
  for (int i =0; i < n; i++){
    int x; cin >> x;
    a[x]++;
  }
  for (int i =0; i < n; i++){
    int x; cin >> x;
    b[x]++;
  }
  vector<int> f, s;
  vector<int> both;
  for (int i = 1; i <= n; i++){
    if (a[i] == 2){
      f.push_back(i);
      f.push_back(i);
    } 
    else if (a[i] == 1){
      both.push_back(i);
    }
    else{
      s.push_back(i);
      s.push_back(i);
    }
  }

  for (auto x: both){
    f.push_back(x);
    s.push_back(x);
  }

  for (int i =0 ;i < 2 * k; i++){
    cout << f[i] << " ";
  }
  cout << '\n';
  for (int i =0 ;i < 2 * k; i++){
    cout << s[i] << " ";
  }
  cout << '\n';
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
