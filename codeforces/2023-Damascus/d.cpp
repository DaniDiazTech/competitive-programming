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

int sieve[MAX];
int coprime[MAX];
void solve(){
  int n, m;
  cin >> n >> m;
  forn(i, m + 10) coprime[m] = 0;
  vii a(n);
  set<int> s;
  forn(i,n){
    int x; cin >> x;
    while (sieve[x] != 0){
      if (s.count(x)) break;
      s.insert(x);
      for (int l = x; l <= m; l += x){
          coprime[l] = x;  
      }
      x /= sieve[x];
    }
  }
  int cnt = 1;
  for (int i = 2; i <= m; i++){
    cout << coprime[i] << " ";
    if (coprime[i] == 0) cnt++;
  }
  cout << cnt << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int n = 1e5 + 100;
  for (int i = 2; i <= n; i++){
    if (!sieve[i]){
      for (int j = i; j <= n; j += i){
        sieve[j] = i;
      }
    }
  }
  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
