// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define fore(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size() 

typedef pair<int, int> pii;
typedef vector<int> vii;

template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2> &p){
    os << p.first <<  " " << p.second;
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX / 2;
const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
int p[MAX], siz[MAX], r[MAX];

int get(int a){
  return p[a] = (a == p[a] ? a : get(p[a]));
}

void link(int u, int v){
  int a =get(u);
  int b =get(v);
  if (a==b) return;
  // if (r[a] == r[b]) r[b]++;
  if (siz[a] > siz[b]){
    swap(a,b); 
  }
  p[b] = p[a];
  siz[b] += siz[a];
}



// int dp[MAX];
void solve(){
  int n, m;
  // Solve with DSU
  cin >> n >> m;
  int cows[n + 1];
  bool f = 1;
  forn(i,n){
    p[i + 1] = i + 1;
    siz[i + 1] = 1;
    cin >> cows[i + 1];
    if (cows[i + 1] != i + 1) f = 0;
  }
  if (f){
    cout << -1 << endl;
    return;
  }
  vector<vector<int>> v;
  forn(i,m){
    int c1,c2,va; cin >> c1 >> c2 >> va;
    v.pb({va, c1, c2});
  }
  sort(all(v));
  // for (auto x: v){
  //   cout << x << endl;
  // }
  int ans = oo;
  int j = m - 1;
  fore(i,1, n + 1){
    // cout << "FIRST: " << get(i) << " " << get(cows[i]) << endl;
    while (j >= 0 && get(i) != get(cows[i])){
      link(v[j][1], v[j][2]);
      // cout << "link :" << v[j][1] << " " << v[j][2] << endl;
      // cout << get(i) << " " << get(cows[i]) << endl;
      ans = min(ans, v[j][0]);
      j--;
    }
  }
  cout << ans << endl;
}

int32_t main() {
  fastInp;
  freopen("wormsort.in", "r", stdin);
  freopen("wormsort.out", "w", stdout);

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
