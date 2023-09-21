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


// int dp[MAX];
void solve(){
  int n;
  cin >> n;
  bool f= 0;
  int a[n], b[n];
  vii p(n + 1);
  forn(i,n){
    int x; cin>> x;
    b[i] = x;
    if (x == 0 && f == 0){
      x = 1;
      f = 1;
    }
    if (x == 0){
      p[i] = 1;
    }
    a[i] = x;
  }
  for (int i = n - 1; i>= 0; i--){
    p[i] += p[i + 1];
  }

  int cnt = 0;
  for (int i = 0; i < n; i++){
    if (a[i] == 1){
      cnt += p[i + 1];
    }
  }

  int cnt2 = 0;
  vii p2(n + 1);
  int first = 0;
  int cntzeroes = 0;

  for (int i = n - 1; i>= 0; i--){
    if (b[i] == 0){
      cntzeroes++;
    }
    else{
      first += cntzeroes;
    }
  }

  f = 0;
  for (int i = n - 1; i>= 0; i--){
    if (b[i] == 1 && f ==0){
      b[i] = 0; 
      f = 1;
    }
    p2[i] = (b[i] == 0);
  }
  for (int i = n - 1; i>= 0; i--){
    p2[i] += p2[i + 1];
  }
  for (int i = 0; i < n; i++){
    if (b[i] == 1){
      cnt2 += p2[i + 1];
    }
  }
  cout << max(cnt, max(first, cnt2))<< endl;
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
