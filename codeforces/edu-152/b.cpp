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


struct cmp{
  constexpr bool operator()(pii &a, pii &b){
    if (a.ff == b.ff) return a.ss > b.ss;
    return a.ff < b.ff;
  }
};


void solve(){
  int n, k;
  cin >> n >> k;
  priority_queue<pii, vector<pii>, cmp> pq;
  vector<int> v;
  forn(i,n){
    int x; cin >> x;
    if (x % k == 0){
      v.pb(i + 1);
    }
    else
      pq.push({x % k, i});
  }
  for (auto x: v){
    cout << x << " ";
  }
  // cout << "NEWWWWWWWW" << endl;
  while (!pq.empty()){
    pii u =pq.top(); pq.pop();
    int x = u.ff, i = u.ss;
    // cout << "NODE: " << u << endl;
    x -= k;
    if (x <= 0){
      cout << i + 1 << " ";
      continue;
    }
    pq.push({x, i});
  } 
  cout << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
