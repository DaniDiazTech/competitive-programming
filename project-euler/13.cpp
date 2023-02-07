// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define FOR(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair

typedef pair<int, int> pii;

const int MAX = 1e6;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

string sum_strings(string n, string m){
  if (m.size() > n.size())
    swap(n, m); 
  reverse(n.begin(), n.end());
  reverse(m.begin(), m.end());

  string result = ""; 

  int reminder = 0;
  int i = 0;
  for (; i < m.size(); i++){
    int x  = (n[i] - '0') + (m[i] - '0');
    x += reminder;
    reminder = 0;
    result += to_string(x % 10);
    if (x >= 10){
      reminder++;
    }
  }
  while (i < n.size() && reminder > 0){
    int x = (n[i] - '0') + reminder;
    i++;
    reminder = 0;

    result += to_string(x % 10);
    if (x >= 10){
      reminder++;
    }
    else
      break;
  }
  if (i == n.size() && reminder > 0){
    result += to_string(reminder);
  }
  else if (i < n.size()){
    for (; i < n.size(); i++)
      result += n[i];
  }

  reverse(result.begin(), result.end());
  return result;
}


// int arr[MAX];
void solve(){
  char ch;
  vector<string> v;
  // Gets large number as std input
  string n = "";
  int i = 0;
  while (cin >> ch){
    i++;
    n += ch;
    if (i  == 50){
      v.pb(n);
      n = "";
      i = 0;
    }
  }

  string s = v[0];
  for (int i =1; i< v.size(); i++){
    s = sum_strings(s, v[i]);
  }   

  cout << string(s.begin(), s.begin() + 10) << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
