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

int binpow(int n, int k){
  if (k == 0) return 1;
  if (k == 1) return n;
  if (k > 61) return oo;
  int bp = binpow(n, k / 2);
  if (bp > 10e5) return oo;
  return  bp * bp * (k & 1 ? n : 1);
}

int sieve[MAX];

void solve(){
  int n , k;
  cin >> n >> k;
  // stores the list of required powers
  // pii = {pi, a1 mod k}
  int ones = 0, zeroes = 0;
  map<vector<pii> , int> mp;
  vector<vector<pii>> a;
  forn(i,n){
    int x; cin >> x;
    if (x == 1){
      ones++;
      continue;
    }
    map<int, int> prime_freq;

    while (sieve[x] != 0){
      prime_freq[sieve[x]]++;
      x /= sieve[x];
    }
    vector<pii> v;
    for (auto p: prime_freq){
      if (p.ss % k != 0){
        v.pb({p.ff, p.ss % k});
      }
    }
    if (sz(v) == 0){
      zeroes++;
      continue;
    }
    sort(all(v));
    mp[v]++;
    a.pb(v);
  } 
  int ans = (ones + zeroes) * (zeroes + ones - 1) /2 ;
  for (auto li: a){
    vector<pii> complement;
    // cout << "ARR: " << li << endl;
    for (auto p: li){
      complement.pb({p.ff, k - p.ss});
    } 
    // cout << "COMP: " << complement << endl;
    // Don't overcount
    ans += mp[complement];
    if (complement == li){
      ans--;
    }
    mp[li]--;
  }
  cout << ans << endl;
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
      for (int j = i; j <= n; j+= i){
        sieve[j] = i;
      }
    }
  }

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
