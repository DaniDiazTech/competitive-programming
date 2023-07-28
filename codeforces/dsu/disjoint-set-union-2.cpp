// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define fore(i, a, b) for (int i = a; i < b; i++) // for in range in python
// #define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.siz() 

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
// const int oo = LLONG_MAX / 2;
// const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";


int p[MAX], siz[MAX], mn[MAX], mx[MAX], r[MAX];

int get(int a){
  // gets label of node a
  return p[a] = (a == p[a] ? a : get(p[a]));
}

void link(int u, int v){
  int a = get(u);
  int b = get(v);
  if (a == b) return;
  // set level of a higher than b
  if (r[a] == r[b]) r[a]++;
  if (r[a] > r[b]){
    swap(a, b);
  }
  siz[b] += siz[a];
  mn[b] = min(mn[b], mn[a]);
  mx[b] = max(mx[b], mx[a]);
  p[a] = p[b]; 
}

void solve(){
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++){
    siz[i] = 1;
    mn[i] = mx[i] = p[i] = i;
  }
  forn(i,m){
    string s;
    cin >> s;
    if (s[0] == 'u'){
      int a,b;
      cin >> a >>b;
      link(a, b);
    }
    else{
      int v; cin >> v;
      int a = get(v); 
      cout << mn[a] << " " << mx[a] << " " << siz[a] << endl;
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
