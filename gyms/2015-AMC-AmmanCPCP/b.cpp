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

// int arr[MAX];
void solve(){
  int n;
  string s;
  cin >> n >> s;
  vector<int> rock(n + 1), paper(n + 1), scissors(n + 1);
  for (int i =0 ; i < n; i++){
    int r = (s[i]  == 'R'),  p = (s[i] == 'P'), sc = (s[i]  == 'S');
    rock[i + 1] = rock[i] + r;
    paper[i + 1] = paper[i] + p;
    scissors[i + 1] = scissors[i] + sc;
  }
  int ans =0;
  for (int x = 0; x <= n; x++){
    for (int y = 0; y <= n; y++){
      int z = n - x - y;
      if (z < 0) break;
      // X: Rock  wins scissors
      // Y: Paper  wins rock
      // Z: Scissors wins paper
      int you = scissors[x] + rock[x + y] - rock[x] + paper[n] - paper[x + y];
      int opponent = paper[x] + scissors[x + y] - scissors[x] + rock[n] - rock[x + y];

      // You win if you have more points that your opponent
      if (you > opponent){
        ans++;
      }

    }
  }
  cout << ans << endl;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
