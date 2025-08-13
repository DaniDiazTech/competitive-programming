// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 1e6 + 2;

vector<int> sieve(N, 0);


vector<int> decomp(int x){

  set<int> s;
  while (x != 1){
    s.insert(sieve[x]);
    x /= sieve[x];
  }
  vector<int> ans;
  for (auto x: s) ans.push_back(x);
  return ans;
}


void calc(int n, int m, vector<int> &b, vector<int>&c, vector<int> &cop){
  // clear c, and cop
  for (int i = 1;i <= m; i++){
    c[i] = cop[i] = 0;
  }

  // m log n
  for (int i = 1; i <= m; i++){
    for (int j = i; j <= m; j += i){
      c[i] += b[j];
    }
  }

  // cout << "B: " << endl;
  // for (auto x: b) cout << x << " ";
  // cout << endl;
  // cout << "C: " << endl;
  // for (auto x: c) cout << x << " ";
  // cout << endl;

  // calculate for each i its prime factors : 
  for (int i = 1; i <= m; i++){
    if (!b[i])continue;
    // calc cop for i

    auto v = decomp(i);
    int k = v.size();


    // cout << i << " PRIME DEC: " << endl;
    // for (auto x : v) cout << x << endl;

    cop[i] = n;
    // PIE
    for (int mask = 1; mask < (1 << k) ; mask++){
      int parity = 0;
      int mul = 1;

      for (int j =0 ;j < k; j++){
        if (mask & (1 << j)){
          mul *= v[j];
          parity++;
        }
      }

      int cnt = c[ mul ];

      if (parity & 1){
        cop[i] -= cnt;
      }
      else{
        cop[i] += cnt;
      }
    }
  }

}

void check_cop(vector<int> &a, vector<int>&cop){
  for (auto x: a){
    cout << cop[x] << " ";
  }
  cout << endl;
}

void solve(){
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m + 1), c(m + 1, 0), cop(m + 1, 0);
  // c[i]: Count of elements divisible by i 

  for (int i = 1; i <= n; i++){
    cin >> a[i - 1];
    b[a[i- 1]]++;
  }

  calc(n,m, b, c, cop);

  // cout << "FIRST: " << endl;
  // check_cop(a, cop);


  // build answer

  int mx = 0;
  int indmx = -1, indmn = -1;
  for (int i = 0;i < n; i++){
    if (cop[a[i]] > mx){
      mx = cop[a[i]];
      indmx = i;
    }
  }

  int mn = n + 1;
  for (int j = 0; j < n; j++){
    if (j == indmx) continue;
    
    if (gcd(a[indmx], a[j]) == 1){
      if (cop[a[j]] < mn){
        mn = cop[a[j]];
        indmn = j;
      }
    }
  }
  

  // re run algorithm (?)
  if (indmx == -1 || indmn == -1){
    cout << 0 << endl;
    return;
  }

  b[a[indmx]]--;
  b[a[indmn]]--;

  calc(n - 2,m, b, c, cop);
  
  
  // cout << "SECOND: " << endl;
  // check_cop(a, cop);
  // cout << endl;

  int r = -1, s = -1;

  for (int i= 0;i < n; i++){
    if (i == indmn || i == indmx) continue;

    if (cop[a[i]] >= 1){
      
      r = i;

      for (int j = i+ 1; j < n; j++){
        if ( j == indmn || j == indmx) continue;

        if (gcd(a[i], a[j]) == 1){
          s = j;
          break;
        }
      }
      break;
    }
  }

  if (r == -1 || s == -1){
    cout << 0 << endl;
  }
  else{
    indmx++;
    indmn++;
    r++;
    s++;
    cout << indmx << " " << indmn << " " << r << " " << s << endl;
  }


}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  

  // run sieve

  for (int i = 2;i < N; i++){
    if (sieve[i]) continue;
    sieve[i] = i;
    for (ll j = (ll)i * i; j < N; j += i){
      sieve[j] = i;
    }
  }

  // auto v = decomp(21822);
  // for (auto x: v) cout << x << ' ';
  // cout << endl;


  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++){
    solve();
  }
}
