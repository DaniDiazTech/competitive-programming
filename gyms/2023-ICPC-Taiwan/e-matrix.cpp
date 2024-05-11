#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using LLL = __uint128_t;
 
ull m;
 
struct matrix{
    array<array<LLL,2>,2> a;
    void init(int id){
        for(int i=0; i<2; i++) for(int j=0; j<2; j++) a[i][j] = i == j ? id : 0;
    }
};
 
matrix operator * (const matrix &a, const matrix &b){
    matrix res; res.init(0);
    for(int i=0; i<2; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++) res.a[i][k] = (res.a[i][k] + a.a[i][j] * b.a[j][k]) % m;
    return res;
}
 
// D[n] = a * D[n-1] - D[n-2]
// D[0] = 2, D[1] = a
 
int main(){
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  matrix d, res; d.init(0); res.init(1);
  ull a, b; cin >> a >> b >> m;
  d.a[0][0] = a; d.a[0][1] = m - 1;
  d.a[1][0] = 1; d.a[1][1] = 0;
  b--;
  for(; b; b >>= 1, d = d * d) if(b & 1) res = res * d;
  cout << ull( (res.a[0][0] * a + res.a[0][1] * 2) % m );
}