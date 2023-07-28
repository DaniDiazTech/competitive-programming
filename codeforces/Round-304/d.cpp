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

const int MAX = 5e6 + 20;
const int MIN = -MAX;
const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int m = 2237;
int prim[m];
int p[MAX];
int dp[MAX];
vii primes;


int f(int i){
  if (i == 1) return 0;
  if (dp[i] != 0) return dp[i];
  for (auto p: primes){
    if (p  > i) break;
    if (i % p == 0){
      return dp[i] = 1 + f(i / p);
    }
  }
  return dp[i] = 1;
}

void solve(){
  int a, b;
  cin >> a >> b;
  // cout << p[a] << " " << p[b] << endl;
  cout << p[a] - p[b] << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int N = 5000001;
  for (int i = 2; i < m; i++){
    if (prim[i]) continue;
    primes.pb(i); 
    for (int j = i; j < m; j+=i){
      prim[j] = i;
    }
  }
  // cout << sz(primes) << endl;
  // cout << "PRIMES: " << primes << endl;


  for (int i = 2; i < N; i++){
    // if (p[i] == 0){
    //   int cnt = 0;
    //   int next = i;
    //   for (int j = i; j < N; j+=i){
    //     if (j == next){
    //       cnt++;
    //       if (next > 3000){
    //         next = -1;
    //       }
    //       else{
    //         next *= i;
    //       }
    //       p[j] += cnt;
    //     }
    //     else{
    //       p[j]++;
    //     }
    //   }
    // }

    p[i] = p[i - 1] + f(i);
  }
  // for (int i= 1 ; i < 100; i++) cout << p[i] << " ";
  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
