// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n;
  cin >> n;
  vector<int> a(33);
  int j = 0;
  while (n){
    a[j++] = n % 2;
    n/=2;
  }

  int carry = 0;
  for (int i = 0;i < 32; i++){
    if (carry && a[i] == 0){
      a[i] = 1;
      carry--;
    }
    else if (carry && a[i] == 1){
      a[i] = 0;
    }
    if (a[i] != 0 && a[i + 1] != 0){
      a[i] = -a[i];
      a[i + 1] = 0;
      carry++;
      i++;
    }
  }
  cout << 32 << endl;
  for (int i =0 ;i < 32; i++){
    cout << a[i] << ' ';
  }
  cout << endl;

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
