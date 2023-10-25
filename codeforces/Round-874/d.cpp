// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  int mxi = -1, smi = -1;

  for (int i = 0;i < n; i++){
    cin >> a[i];
    if (a[i] == n){
      mxi = i;
    }
    if (a[i] == n - 1) smi =i;
  }
  if (n == 1){
    cout << 1 << '\n';
    return;
  }

  vector<int> ans(n);

  // only care about
  if (mxi == 0 ){
    // try everything
    // care about second
  }
  else{
    // try r - 1 and n - 1
    smi = mxi;
  }

  // smi - 1
  vector<int> cur(n);

  for (int i = smi; i < n; i++) ans[i - smi] = a[i], cur[i - smi] = a[i];
  vector<int> rev;
  int ind = n - smi + 1;

  for (int l = smi - 1; l >= 0 ; l--){

    rev.push_back(a[l]);

    for (int j = 0; j < rev.size(); j++){
      cur[ind + j - 1] = rev[j];
    }

    for (int j = 0; j < l; j++){
      cur[ind + rev.size()- 1 +  j] = a[j];
    }

    // cout << "NEW: \n";
    // for (auto x: cur){
    //   cout <<x  << " ";
    // }
    // cout << '\n';

    // compare
    for (int j = 0; j < n; j++){
      if (cur[j] > ans[j]){
        ans = cur;
        break;
      }
      else if (cur[j] < ans[j]) break;
    }
  }

  // last
  cur[0] = a[n - 1];
  rev.clear();
  ind = 1;

  for (int l = n - 1; l >= 0 ; l--){

    rev.push_back(a[l]);

    for (int j = 0; j < rev.size(); j++){
      cur[ind + j - 1] = rev[j];
    }

    for (int j = 0; j < l; j++){
      cur[ind + rev.size() - 1 +  j] = a[j];
    }

    // cout << "NEW: \n";
    // for (auto x: cur){
    //   cout <<x  << " ";
    // }
    // cout << '\n';

    // compare
    for (int j = 0; j < n; j++){
      if (cur[j] > ans[j]){
        ans = cur;
        break;
      }
      else if (cur[j] < ans[j]) break;
    }
  }

  for (auto x: ans) cout << x << " ";
  cout << '\n';
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
