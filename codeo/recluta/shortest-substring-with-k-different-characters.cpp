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

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX / 2;
const int ooo = LLONG_MIN / 2;
const int mod = 1e9 + 7;

// int arr[MAX];
void solve(){
  string s; int k; cin >> s >> k;
  set<char> st;
  map<char,int> mp;
  int ans = oo;
  for (int l = 0, r = 0; r < (int)s.size(); r++){
    mp[s[r]]++;
    st.insert(s[r]);
    while (st.size() >= k){
      ans = min(ans, r - l  + 1);
      // Can try to advance l
      if (mp[s[l]] <= 1){
        // Only remove and advance if size > k
        if (st.size() > k){
          mp[s[l]]--;
          st.erase(s[l]);
          l++;
        }
        else{
          break;
        }
      }
      else{
        // Can advance
        mp[s[l]]--;
        l++;
      }
      ans = min(ans, r - l  + 1);
    }
  }
  cout << (ans == oo ? -1: ans) << endl;
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
