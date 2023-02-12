// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define FOR(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair

typedef pair<int, int> pii;

const int MAX = 1e6;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

// int arr[MAX];
void solve(){
  int n;
  cin >> n;
  map<string, vector<int>> mp;
  forn(i,n){
    string s; int sol, p;
    cin >> s >> sol >> p;
    mp[s] = {sol, p};
  }

  string best = "";
  int bscore = -1, bpenaltie = -1;
  for (auto x: mp){
    if (x.second[0] > bscore){
      best = x.first;
      bscore = x.second[0];
      bpenaltie = x.second[1];
    }
    else if (x.second[0] == bscore){
      if (x.second[1] < bpenaltie){
        best = x.first;
        bscore = x.second[0];
        bpenaltie = x.second[1];
      }
    }
  }
  cout << best << endl;
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
