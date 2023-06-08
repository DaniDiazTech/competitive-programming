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

const int MAX = 1e5 + 10;
const int MIN = -MAX;
// const int oo = LLONG_MAX / 2;
// const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;

vii g[MAX];
bool dfs(int u, int search){
  for (auto x: g[u]){
    if (x == search){
      return true;
    }
    else{
      return dfs(x, search);
    }
  }
  return false;
}


int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int n;
  cin >> n;
  forn(i,n - 1){
    int a, b; cin >> a >> b;
    g[b].pb(a);
  }

  int q; cin >> q;
  forn(i,q){
    int a, b; cin >> a >> b;
    if (a == b){
      cout << "Yes" << endl; continue;
    }
    queue<int> q;
    q.push(b);
    bool f= 0;
    while (!q.empty() && !f){
      int u = q.front();
      q.pop();
      for (auto x: g[u]){
        if (x == a){
          f = 1;
          break;
        }
        else{
          q.push(x);
        }
      }
    }
    cout << (f?"Yes":"No") << endl;
  }

  return 0;
}
