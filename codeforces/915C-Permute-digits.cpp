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

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX;
const int ooo = LLONG_MIN;
const int mod = 1e9 + 7;

int fq[10];
string a,b;
int ans = 0;
void solve(string s){
  if (sz(s) == sz(b)){

  }
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  cin >>a >>b;
  if (sz(a) < sz(b)){
    sort(a.rbegin(), a.rend());
    cout << a << endl;
  }
  else{
    forn(i,sz(a)){
      fq[a[i] - '0']++;
    }
    solve("");
    cout << ans << endl;
  }

  return 0;
}
