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

void search(string original, string permutation,  vector<int> &chosen, set<string> &v){
  if (permutation.size() == original.size()){
    v.insert(permutation);
  }
  else{
    for (int i = 0; i < (int)original.size(); i++){
      if (chosen[i]) continue;
      chosen[i] = true;
      permutation.push_back(original[i]);
      search(original, permutation, chosen, v);
      chosen[i] = false;
      permutation.pop_back();
    }
  }
}

// int arr[MAX];
void solve(){
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  set<string> v;
  vector<int> chosen(s.size() + 1);
  string perm = "";
  search(s, perm, chosen, v);

  cout << v.size() << endl;
  for (auto x: v) cout << x << endl;

}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
