// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";


vector<string> a;

void gene(const string & s){

  int n = (int)s.size();
  string fn, sn, fs, ss;
  string cur;
  int i= 0;

  vector<string> names;

  while (i < n){
    if (s[i] == ' '){
      names.push_back(cur);
      cur = "";
    }
    else{
      cur += s[i];
    }
    i++;
  }

  fn = names[0];

  if (names.size() == 3){
    fs = names[1]  ;
    ss = names[2];
  }
  else{
    sn = names[1];
    fs = names[2]  ;
    ss = names[3];
  }
  if (sn.size()) sn = sn[0];

  int m = fn.size();
  // generate
  for (int i =0 ;i < m; i++){
    string x;
    x += fn.substr(0, i + 1); 
    x += sn;
    x += fs;
    a.push_back(x);
    for (int j = 0;j < min(i + 1, (int)ss.size()); j++){
      x += ss[j];
      a.push_back(x);
    }
  }

  // last characters
  if ((int)ss.size() > m){
    string x;
    x += fn.substr(0, m); 
    x += sn;
    x += fs;
    x += ss.substr(0, m);
    int j = m;
    while (j < (int)ss.size()){
      x += ss[j];
      a.push_back(x);
      j++;
    }
  }
}

void print(){
  cout << a.size() << endl;
  for (auto x: a) cout << x << endl;
}

bool in(int m){
  cout << a[m] << endl;

  int x; cin >> x;
  return x == 1;
}

void solve(){
  string s;
  getline(cin, s);
  s += ' ';

  gene(s);

  // print();

  int l = 0, r = a.size() - 1;

  while (l + 1 < r){
    int m = (l + r) / 2;
    if (in(m)) l = m;
    else r = m;
  }

  cout << "! " << a[r] << endl;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
