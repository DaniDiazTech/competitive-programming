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

// Count the minimum number of inversions,
// or bubble sort steps that are needed to sort the array

int a[MAX];


int merge(int l, int q, int r){
  int cnt = 0;
  int n1 = q - l + 1, n2 = r - q;
  int la[n1], ra[n2];

  for (int i = 0; i <n1; i++){
    la[i] = a[l + i];
  }
  for (int i = 0; i < n2; i++){
    ra[i] = a[q + i + 1];
  }

  int x = 0, y = 0, k = l;
  // cout << "L: " << l << " Q: "  << q << " R: " << r << endl;
  while (x < n1 && y < n2){
    // Inversion count
    if (la[x] > ra[y]){
      cnt += (q + 1) - (l + x);
      a[k] = ra[y];
      y++;
    }
    else{
      a[k] = la[x];
      x++;
    }
    k++;
  }

  while (x < n1){
    a[k] = la[x];
    x++;
    k++;
  }

  while (y < n2){
    a[k] = ra[y];
    y++;
    k++;
  }
  return cnt;
}

int mergeSort(int l, int r){
  // Divides array

  int cnt = 0;
  if (l < r){
    int q = (l + r) / 2;
    cnt += mergeSort(l, q);
    cnt += mergeSort(q + 1, r);
    cnt += merge(l, q, r);
  }
  return cnt;
}


void solve(){
  int n;
  cin >> n;
  forn(i,n) cin >> a[i];
  cout << mergeSort(0, n -1) << endl;
  forn(i,n) cout << a[i] << " ";
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
