// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 1e5;
int n;

vector<int> X(16), Y(16);

ld dis(int i, int j){
  return sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]));
}


vector<int> mask(16);


ld go(int i){
  if (i == 2 * n) return 0;

  ld ans = 1e15;

  mask[i] = 1;

  int prev = -1;
  bool f= 0;
  for (int j = i + 1;j < 2 * n; j++){
    if (!f){
      if (!mask[j]){
        f = 1;
        prev = j; 


        // find next one
        int nxt = 2 * n;
        for (int k = j + 1; k < 2 * n; k++){
          if (!mask[k]){
            nxt = k;
            break;
          }
        }

        mask[j] = 1;
        ans = min(ans, dis(i, j) + go(nxt));
        mask[j] = 0;
      }
    }
    else{
      if (!mask[j]){
        mask[j] = 1;
        ans = min(ans, dis(i, j) + go(prev));
        mask[j] = 0;
      }
    }
  }

  mask[i] = 0;

  return ans;
}

void solve(){
  for (int i =0 ;i < 2 * n; i++){
    string s; cin >> s;
    int x,y; cin >> x >> y;
    X[i] = x;
    Y[i] = y;
  }
  cout << go(0);
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  cout << fixed << setprecision(2);
  int t = 1;
  while (cin >> n){
    if (n == 0) break;

    cout <<  "Case " << t++ << ": ";
    solve();
    cout << '\n';
  }
}
