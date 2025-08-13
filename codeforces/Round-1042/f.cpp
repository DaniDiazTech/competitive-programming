// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  ll n;
  cin >> n;
  string a, b; cin >> a >> b;

  vector<ll> pa(n + 1) , pb(n + 1);

  for (int i = 1;i <= n; i++){
    pa[i] = pa[i - 1] + (a[i - 1] == '0'  ? -1ll: 1ll);
    pb[i] = pb[i - 1] + (b[i - 1] == '1' ? -1ll: 1ll);
  }
  pa[0] = pb[0] =  -1e15;
  sort(pa.begin(), pa.end());
  sort(pb.begin(), pb.end());

  ll ans = n * n * (n + 1);
  ll res = 0;

  // count for A
  for (int K = 0; K < 2; K++){
    ll i = 1, j = 1 ;
    while (i <= n && j <= n){
      if (pa[i] >= pb[j]){

        res -= pb[j] * (n - i+ 1);
        j++;
      }
      else{
        res += pa[i] * (j - 1);
        i++;
      }
    }

    while (i <= n){
      res += pa[i++] * (j - 1);
    }
    while (j <= n){
      res -= pb[j++] * (n - i + 1);
    }

    swap(pa, pb);
  }


  cout << (ans - res)  / 2 << endl;
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
