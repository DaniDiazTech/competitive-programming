// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

void solve(){
  int n, x;
  cin >> n >> x;

  int a[n];
  for (int i =0 ;i < n; i++ ) cin >> a[i];

  int acum  = 0 , prev = 0;
  int c= 0;

  priority_queue<int> pq;

  for (int i = 1; i < n; i++){
    if (i * x - acum >= a[i]){
      acum += a[i]; 
      pq.push(a[i]);
      c++;
    }
    else{
      acum += a[i];
      pq.push(a[i]);
      acum -= pq.top();
      pq.pop();
    }
  }
  cout << c << endl;
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
