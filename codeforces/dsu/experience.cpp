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

int p[MAX], experience[MAX], pre[MAX], r[MAX];
vii g[MAX];

int get(int a){
  return p[a] = (a == p[a] ? a : get(p[a]));
}

int get_prev(int a){
  int s = pre[a];
  if (g[a].empty()) return pre[a];
  // cout << endl;
  // cout << a << " next:  " <<  g[a] << "current: " << s << endl;
  for (auto x: g[a]){
    s += get_prev(x);
  }
  return s;
}

void link(int u, int v){
  int a = get(u);
  int b = get(v);
  if (a == b) return;
  if (r[a] == r[b]) r[a]++;
  if (r[a] > r[b]) swap(a,b), swap(u,v);
  p[a] = p[b];
  g[a].pb(b);
  pre[a] = experience[a] - experience[b];
}

void init(int n){
  fore(i,1,n + 1){
    p[i] = i;
    experience[i] = 0;
    r[i] = 0;
  }
}

// int dp[MAX];
void solve(){
  int n, m;
  cin >> n >> m;
  init(n);
  forn(i,m){
    string s;
    cin >> s;
    if (s == "add"){
      int x, v; cin >> x >> v;
      int a = get(x);
      experience[a] += v;
    }
    else if (s == "join"){
      int x, y; cin>> x >> y;
      link(x,y);
    }
    else{
      int x; cin >> x;
      cout << experience[get(x)] + get_prev(x)  << endl;
    }
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
