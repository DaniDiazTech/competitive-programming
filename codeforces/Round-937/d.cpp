// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

set<int> v;
string s;
const int N = 6;

void create(int i){
  if  (i == N){
    int x = stoi(s);
    if (x != 0 && x != 1){
      v.insert(x);
    }
    return;
  }

  s += "1";
  create(i + 1);
  s.pop_back();
  s += "0";
  create(i + 1);
  s.pop_back();
}



void solve(){
  int n;
  cin >> n;
  if (v.count(n)){
    cout << yes << endl;
    return;
  }
  for (auto x: v){
    while (n % x == 0){
      n /= x;
    }
  }
  cout << (n == 1  ? yes: no) << endl;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;
  create(0);
  for (int t = 1; t <= tc; t++){
    solve();
  }
}
