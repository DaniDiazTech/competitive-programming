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
  int a[n][n - 1];

  vector<int> v;
  set<int> s;
  for (int i = 1; i <=n;i++) s.insert(i);

  for (int i = 0; i < n;i++){
    for (int j = 0; j < n - 1; j++){
      cin >> a[i][j];
    }
  }

  // First perm
  for (int j = 0; j < n -1; j++){
    s.erase(a[0][j]);
    v.pb(a[0][j]);
  }
  int ms = *s.begin();
  map<int, int> mp;
  for (int i = 1; i < n; i++){
    for (int j = 0; j < n - 1; j++){
      if (a[i][j] == ms){
        // Get before
        if (j == 0){
          mp[-1]++;
        }
        else{
          mp[a[i][j - 1]]++;
        }
      }
    }
  }

  if (n == 3){
    map<int, int> ml;
    map<int, int> mr;
    for (int i = 0; i < n; i++){
      ml[a[i][0]]++;
      mr[a[i][1]]++;
    }
    int l = (*max_element(ml.begin(), ml.end(), [](const auto &x, const auto &y){return x.second < y.second;})).first;
    int r = (*max_element(mr.begin(), mr.end(), [](const auto &x, const auto &y){return x.second < y.second;})).first;
    cout << l << " " << 6 - (l + r) << " " <<  r << endl;
    return;
  }

  int bf = -1 ;
  if (mp[-1] >= 2){
    cout << ms << " ";
    for (auto x: v) cout << x << " ";
  }
  else{
    for (auto x: mp){
      if (x.second >= 2){
        bf = x.first; 
        break;
      }
    }    
    for (int i =0; i < n - 1; i++){
      cout << a[0][i] << " ";
      if (a[0][i] == bf) cout << ms << " ";
    }
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
