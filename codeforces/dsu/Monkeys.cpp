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


int p[MAX], r[MAX], ans[MAX];
int get(int a){return (a == p[a] ? a : get(p[a]));}
void link(int a, int b){
  a = get(a);
  b = get(b);
  if (a == b) return;
  if (r[a] == r[b]) r[a]++;
  if (r[b] > r[a]) swap(a,b);
  p[b] = a;
}
void solve(){
  int n, m;
  cin >> n >> m;
  map<int, pii> left, right;
  fore(i,1,n){
    int l, r; cin >> l >> r;
    if (l != -1){
      left[i] = {i, l};
    }
    if (r != -1){
      right[i] = {i, r};
    }
    p[i] = i;
    ans[i] = oo;
  }
  vector<pii> q;
  forn(i,m){
    int num,t;
    cin  >> num >> t;
    if (t == 1){
      q.pb(left[num]);
      left.erase(num);
    }
    else{
      q.pb(right[num]);
      right.erase(num);
    }
  }
  // create dsu without q
  for (auto x: left){
    link(x.ss.ff, x.ss.ss);
  }
  for (auto x: right){
    link(x.ss.ff, x.ss.ss);
  }
  for (int i =0 ; i < m; i++){
    
  }
}
int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
