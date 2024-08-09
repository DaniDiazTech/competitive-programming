// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";


void solve(){
  int n, m;
  cin >> n >> m;
  vector<int> negatives, positives;
  for (int i = 0 ;i < n ; i++){
    int x; cin >> x;
    if ( x > 0) positives.push_back(x);
    else negatives.push_back(x);
  } 

  vector<int> negSpecial, posSpecial;
  set<int> special;
  for (int i = 0;i < m; i++){
    int x; cin >> x;
    if (x > 0){
      posSpecial.push_back(x);
    }
    else negSpecial.push_back(x);

    special.insert(x);
  }

  function< int(vector<int>, vector<int>) > f = [&](vector<int> a, vector<int> b){
    int n = a.size(), m = b.size();
    if (n == 0 || m == 0) return 0;
    map<int,int> mp;

    vector<int> c(n);
    for (int i = 0;i < n; i++){
      c[i] = abs(a[i]);
      mp[c[i]] = a[i];
    }


    vector<int> prefix(n, 0);

    sort(c.begin(), c.end());

    for (int i = 0; i < n; i++){
      if (special.count(mp[c[i]])){
        prefix[i]++;     
      }

      if (i > 0) prefix[i] += prefix[i - 1];
    }

    for (auto &val : b) val = abs(val);
    sort(b.begin(), b.end());

    int ans = prefix.back();

    // for (auto x: c) cout << x << " ";
    // cout << endl;
    // for (auto x: b) cout << x << " ";
    // cout << endl;
    // for (auto x: prefix) cout << x << " ";
    // cout << endl;
    

    // Move a group of boxes to b_i
    for (int i = 0;i < m ; i++){
      int l = -1, r = n;
      while (l + 1 < r){
        int m = (l + r) / 2;
        if (c[m] <= b[i]){
          l = m;
        }
        else r = m;

      }

      if (l == -1) continue;

      int sz = l + 1;

      // Last element of b greater or equal to b[i] - sz
      l = -1, r = i;
      while (l + 1 < r){
        int m = (l + r) / 2;
        if (b[m] >= b[i] - sz + 1) r = m;
        else l = m;
      }



      int specialbefore = i - r + 1, extra = (prefix.back() - prefix[sz - 1]);
      int best = specialbefore + extra;
      ans = max(ans, best);
      // cout << i << "  " << b[i] << " " << sz << " " << specialbefore << " " << extra  << " "  << best << endl;

    }

    return ans;
  };

  int ansA = f(negatives, negSpecial),  ansB = f(positives, posSpecial);

  cout << ansA + ansB << endl;
}


int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
