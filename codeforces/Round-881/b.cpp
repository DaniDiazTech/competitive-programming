// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  ll sum = 0;
  ll op = 0;
  ll cnt = 0;
  int a[n + 1];
  a[n] = 1;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int prev = 0;
  for (int i = 0; i < n +1; i++){
    if (a[i] <= 0){
      if (a[i] < 0){
        cnt++;
      }
    }
    else{
      op += (cnt > 0);
      cnt = 0;
    }
    prev = a[i];
    sum += abs(a[i]);
  }
  cout << sum - 1 << " " << op << '\n';
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
