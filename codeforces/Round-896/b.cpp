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
const int oo = LLONG_MAX / 3;
const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

int dis(pii a, pii b){
  return abs(a.ff - b.ff) + abs(a.ss - b.ss);
}
void solve(){
  int n, k , a , b;
  cin >> n >> k >> a >> b;
  a--; b--;;
  vector<pii> v;
  forn(i,n){
    int x, y; cin >> x >> y;
    v.pb({x,y});
  }
  int mn = dis(v[a],v[b]);
  if (a < k){
    if (b < k){
      mn =0;
    }
    else{
      // a yes but b no
      forn(i,k){
        mn = min(dis(v[i], v[b]), mn);
      }
    }
  }
  else{
    if (b < k){
      forn(i,k){
        mn = min(dis(v[i], v[a]), mn);
      }
    }
    else{
      // try cost from a to major, and cost from closest major to b
      int other = oo;
      forn(i,k){
        other = min(dis(v[i], v[a]), other);
      }
      int mtob = oo;
      forn(i,k){
        mtob = min(dis(v[i], v[b]), mtob);
      }
      mn = min(other + mtob, mn);

    }
  }
  cout << mn << endl;
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
