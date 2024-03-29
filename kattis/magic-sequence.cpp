// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define fore(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size() 

typedef pair<int, int> pii;

const int MAX = 1e6;
const int MIN = -MAX;
const int oo = LLONG_MAX;
const int ooo = LLONG_MIN;
const int mod = 1e9 + 7;
// Not working

void countsort(int a[], int n, int place, int base=10){
  int fq[base] = {0};
  int out[n];

  forn(i,n){
    fq[(a[i] / place) % base]++;
  }
  fore(i,1,base) fq[i] += fq[i - 1];

  for (int i = n -1; i>=0; i--){
    int d = (a[i]/ place) % base;
    out[fq[d] - 1] = a[i];
    fq[d]--;
  }

  forn(i,n){
    a[i] = out[i];
  }
}

void radixsort(int a[], int n, int base=10){
  int mx = a[max_element(a, a + n) - a]; 
  for (int place = 1; mx / place > 0; place *= base){
    countsort(a, n, place, base);
  }
}

// int arr[MAX];
void solve(){
  int n;
  cin >> n;

  int a, b, c, x ,y; cin >> a >> b >> c >> x >> y;
  int s[n];
  s[0] = a;

  fore(i,1, n){
    s[i] = (s[i - 1] * b + a) % c;
  }
  radixsort(s, n, 31623);
  int ans = 0;
  forn(i,n){
    ans = (ans * x  +  s[i]) % y;
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
