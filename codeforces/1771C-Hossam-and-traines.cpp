// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define fore(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define vii vector<int> 
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size() 

typedef pair<int, int> pii;

template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2> &p){
    os << p.first <<  " " << p.second;
    return os;
}

const int MAX = 1e5 + 10;
const int MIN = -MAX;
const int mod = 1e9 + 7;


vii primes;
int p[MAX];
int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  int N = 31623;
  for (int i =2 ; i < N ; i++){
    if (!p[i]){
      primes.pb(i);
      for (int j = i; j < N; j += i){
        p[j] = i;
      }
    }  
  }
  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
  int n;
  cin >> n;
  int a[n];
  vii mp(MAX);
  unordered_set<int> s;
  int cnt= 0, ans = 0;
  forn(i,n){
    cin >> a[i];
  }
  forn(i,n){
    if (ans) break;
    int x = a[i];
    for (int i = 0; i < sz(primes); i++){
      if (x < primes[i]) break;
      if (x % primes[i] != 0) continue;
      while (x % primes[i] == 0){
        x /= primes[i];
      }
      mp[primes[i]]++; 
      if (mp[primes[i]] >= 2){
        ans = 1;
        break;
      }
    }
    if (x > 1){
      cnt++;
      s.insert(x);
    }
  }
  if (sz(s) < cnt){
    ans = 1;
  }
  cout << (ans ? "YES": "NO") << endl;
  }
  return 0;
}
