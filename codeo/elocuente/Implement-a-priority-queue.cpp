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

struct CMP{
  public:
  bool operator() (pair<int, string> &p1, pair<int, string> &p2){
    if (p1.first == p2.first)
      return p1.second > p2.second;
    return p1.first < p2.first;
  };
};

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  priority_queue<pair<int, string> ,vector<pair<int, string>>, CMP> pq;
  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    string op; cin >> op;
    if (op == "Insert"){
      string s; int p; cin >> s >> p;
      pq.push({p, s});
    }
    else if (op == "GetMax"){
      auto a = pq.top();
      cout <<  a.second << endl;
    }
    else if(op == "PopMax"){
      pq.pop();
    }
  }
  return 0;
}
