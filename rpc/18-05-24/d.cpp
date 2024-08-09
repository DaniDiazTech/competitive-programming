// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

bool even = 1;
void print(){
  cout << (even ? "even" : "odd") << '\n';
}
void solve(){
  int n, m;
  cin >> n >> m;
  string buf, s;
  getline(cin, buf);
  getline(cin, s);

  int t, i;
  t = i = 0;
  vector<int> id(n), a(n);
  s += '$';

  vector<int> zeroes;
  zeroes.push_back(0);

  string num;
  for (auto x: s){
    if (x == ' ') continue;
    if (isdigit(x)){
      num += x;
    }
    else{
      int y = stoi(num) % 2 == 0;
      zeroes.back() += y;
      a[i]= y;
      id[i++] = t;
      if ( x == '+' || x=='-'){
        t++;
        zeroes.push_back(0);
      }
      num = "";
    }
  }


  for (auto x: zeroes){
    // quantity of zeros
    if (x == 0){
      even = !even;
    }
  }

  print();


  // for (auto x: zeroes){
  //   cout << x << ' ';
  // }
  // cout << endl;

  while (m--){
    int j, x;
    cin >> j >> x;
    j--;

    int y = x % 2 == 0;

    int ind = id[j];

    if (a[j] != y){
      int x = zeroes[ind];

      zeroes[ind] += (a[j] == 1 ? -1 : 1);
      a[j] = y;

      if (x == 0){
        // change
        even = !even; 
      }
      else if (x != 0 && zeroes[ind] == 0){
        even = !even; 
      }
    }

    // for (auto x: zeroes){
    //   cout << x << ' ';
    // }
    // cout << endl;
    
    print();
  }
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
