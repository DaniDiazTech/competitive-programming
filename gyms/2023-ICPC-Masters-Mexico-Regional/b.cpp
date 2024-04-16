// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

ll Mod(ll a) 
{
    if(a>=0) return a%mod;
    else 
    {
        ll k = (abs(a)+mod-1)/mod;
        return (a+(mod*k))%mod;
    }
}

// General matrix multplication
vector<vector<ll>> multiply_matrix(vector<vector<ll>>& A, vector<vector<ll>>& B){

  // Matrix m * n, n * p
  int m = A.size(), p = B[0].size();
  vector<vector<ll>> C(m, vector<ll>(p));
  
  int n = A[0].size(), nn = B.size();

  // Can't multiply
  if (n != nn){
    return C;
  }

  for (int i = 0;i < m; i++){
    for (int j = 0;j < p; j++){
      ll sum = 0;
      for (int k = 0; k < n; k++){
        sum = Mod(sum + A[i][k] * B[k][j]);
      } 
      C[i][j] = sum;
    }
  }

  return C;
}


void expFastItr(vector<vector<ll>>& A, ll b, vector<vector<ll>>& X){

    for(int i = (int)log2(b)+1; i >=0; i--){
        X = multiply_matrix(X,X);
        if(b & (1LL << i)) X = multiply_matrix(X,A);
    }

}


void solve(){
  ll k; cin >> k;
  int n = 4;
  vector<vector<ll>> X = {{0, 1 , 0, 0}, {0, 0, 1, 0}, {0, 0 , 0 , 1}, {-1, -1, -1, 4}};
  vector<vector<ll>> f = {{1}, {2}, {3}, {17}};

  vector<vector<ll>> XK(n, vector<ll>(n));

  for (int i =0 ;i < n; i++){
    for (int j= 0;j < n; j++){
      if (i == j)
        XK[i][j] = 1;
    }
  }

  expFastItr(X, k, XK);


  vector<vector<ll>> ans = multiply_matrix(XK, f);

  cout << ans[0][0] << '\n';
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
