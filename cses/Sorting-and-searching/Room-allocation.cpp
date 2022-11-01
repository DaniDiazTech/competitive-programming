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

const int MAX = 2 * 1e5 + 10;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

auto comp = [](const vector<int> &left, const vector<int> &right){
    return left[0] > right[0];
  };

void solve_pq(){
  int n;
  cin >> n;
  vector<vector<int>> a;
  forn(i,n){
    vector<int> temp(3);
    cin >> temp[0] >> temp[1];
    temp[2] = i;
    a.pb(temp);
  };

  sort(a.begin(), a.end());
  // End day, room
  // Priority queue with custom comp function
  priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
  
  int room = 1;
  vector<int> v;
  vector<int> rooms(n);

  for (int i = 0; i < n; i++){
    if (!pq.empty()){
      if (pq.top()[0] < a[i][0]){
        // Can use the room again 
        int r = pq.top()[1];
        rooms[a[i][2]] = r;
        pq.pop();
        v = {a[i][1], r};
        pq.push(v);
      }
      else{
        // Can't use the current room
        room++;
        v = {a[i][1], room};
        pq.push(v);
        rooms[a[i][2]] = room;
      }
    }
    else{
      v = {a[i][1], room};
      pq.push(v);
      rooms[a[i][2]] = room;
    }
  } 

  cout << room << endl; 
  for (auto x: rooms) cout << x << " ";
}

void solve(){
  int n;
  cin >> n;
  vector<vector<int>> a;
  forn(i,n){
    vector<int> temp(3);
    cin >> temp[0] >> temp[1];
    temp[2] = i;
    a.pb(temp);
  };

  sort(a.begin(), a.end());
  // End day, room
  // Set :()
  set<vector<int>> s;
  
  int room = 1;
  vector<int> v;
  vector<int> rooms(n);

  for (int i = 0; i < n; i++){
    if (!s.empty()){
      auto it = s.begin();
      if ((*it)[0] < a[i][0]){
        // Can use the room again 
        int r = (*it)[1];
        rooms[a[i][2]] = r;
        s.erase(it);
        v = {a[i][1], r};
        s.insert(v);
      }
      else{
        // Can't use the current room
        room++;
        v = {a[i][1], room};
        s.insert(v);
        rooms[a[i][2]] = room;
      }
    }
    else{
      v = {a[i][1], room};
      s.insert(v);
      rooms[a[i][2]] = room;
    }
  } 

  cout << room << endl; 
  for (auto x: rooms) cout << x << " ";
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
