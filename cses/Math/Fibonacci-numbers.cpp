// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

/*
Tested: https://codeforces.com/gym/104758/submission/255399948
General matrix multiplication:

Given A (m * n), and B (n * p) matrices,
compute C = AB, of size (m * p)
where C_(ij) = sum(k -> [0, n))( A_(ik) * B_(kj))

Complexity: O(n^3)

Implemeted with mod 10^9 + 7
*/
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
        sum = sum + A[i][k] * B[k][j];
        if (sum < 0){
          ll q = (abs(sum) + mod - 1) / mod;
          sum = (sum + (mod * q)) % mod;
        }
        else{
          sum %= mod;
        }
      } 
      C[i][j] = sum;
    }
  }

  return C;
}

/*
Fast matrix exponentiation:

Given A (n * n) matrix, compute A^b (n * n)

Idea: We know A^b = A^(b / 2) * A^(b / 2).
Let X be the identity matrix.



Complexity: O(n^3 * log(b))
*/

vector<vector<ll>> expo_matrix(vector<vector<ll>>& A, ll b){
  int n = A.size();

  vector<vector<ll>> X(n, vector<ll>(n));
  for (int i = 0;i < n; i++) X[i][i] = 1;

  for(int i = (int)log2(b)+1; i >=0; i--){
    X = multiply_matrix(X,X);
    if(b & (1LL << i)) X = multiply_matrix(X,A);
  }
 
  return X;
}


void solve(){
  ll n;
  cin >> n;
  vector<vector<ll>> x = {{0, 1}, {1, 1}};
  vector<vector<ll>> c = {{0}, {1}};
  auto xtok = expo_matrix(x, n);
  cout << (multiply_matrix(xtok, c))[0][0] << '\n';
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
