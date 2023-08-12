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


int p[MAX], r[MAX];
int get(int a){
  return (a == p[a] ? a : get(p[a]));
}

void link(int u, int v){
  int a = get(u);
  int b = get(v);
  if (a == b) return;
  if (r[a] == r[b]) r[b]++;
  if (r[a] > r[b]) swap(a,b);
  p[a] = b;
}

void solve(){
  int n, m, q;
  cin >> n >> m >> q;
  forn(i,n){
    p[i + 1] = i + 1;
  }
  vector<pii> v;
  forn(i,m){
    int a, b; cin >> a >> b;
    v.pb({a,b});
  }
  vector<vii> queries;
  forn(_,q){
    string s; cin >>s;
    int a,b; cin >> a >>b;
    queries.pb({(s[0] == 'a'), a, b});
  }
  reverse(all(queries));
  vector<bool> ans;
  forn(i,q){
    if (queries[i][0]){
      ans.pb(get(queries[i][1]) == get(queries[i][2]));
    }
    else{
      link(queries[i][1], queries[i][2]);
    }
  }
  reverse(all(ans));
  for (auto x: ans){
    if (x){
      cout << yes;
    }
    else cout << no;
    cout << endl;
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
