// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

string s;
int n;
pair<string, int> solve(int i, string cur){
  cout << "ENTRY" << endl;
  if (i >= n){
    return {"", n};
  }
  if (s[i] == ']'){
    return {cur, i};
  }
  else if (s[i] == '['){
    pair<string, int> p = solve(i + 1, "");
    pair<string, int> p2 = solve(p.second + 1, "");
    return {p.first + cur + p2.first, p2.second};
  }
  else{
    return solve(i + 1, cur + s[i]);
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  while (getline(cin, s)){
    s = "[" + s + "]";
    n = s.size();
    cout << (solve(0, "")).first << '\n';
  }
}
