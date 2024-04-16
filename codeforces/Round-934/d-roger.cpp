#include <bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define pb push_back
 
typedef long long ll;
typedef pair <int,int> pii;
 
/// Complexity: O(|N|)
/// Tested: https://tinyurl.com/y6upxbpa
///to = i - from[i];
///len = to - from[i] + 1 = i - 2 * from[i] + 1;
vector<int> manacher(string &s) {
  int n = s.size(), p = 0, pr = -1;
  vector<int> from(2*n-1);
  for(int i = 0; i < 2*n-1; ++i) {
    int r = i <= 2*pr ? min(p - from[2*p - i], pr) : i/2;
    int l = i - r;
    while(l > 0 && r < n-1 && s[l-1] == s[r+1]) --l, ++r;
    from[i] = l;
    if (r > pr) {
      pr = r;
      p = i;
    }
  }
  return from;
}
 
const int N = 200'005;
 
int n, q;
int same[N], same_parity[N];
vector <int> pal_from;
 
void calc ( string &s ) {
    same[n-1] = 1;
    for ( int i = n-2; i >= 0; --i )
        same[i] = s[i] == s[i+1]? same[i+1] + 1: 1;
    same_parity[n-1] = same_parity[n-2] = 1;
    for ( int i = n-3; i >= 0; --i )
        same_parity[i] = s[i] == s[i+2] ? same_parity[i+2] + 2 : 1;
}
 
ll gauss ( int n ) {
    return ll(n)*(n+1) / 2LL;
}
 
ll even_gauss ( int n ) {
    return 2LL*gauss ( n/2 );
}
 
ll ans_query ( int l, int r ) {
    --l, --r;
    if ( same[l] >= r-l+1 ) return 0;
    if ( l + same_parity[l] >= r and l+same_parity[l+1] >= r-1 ) 
        return even_gauss ( r-l+1 );
    if ( pal_from[l+r] <= l ) return gauss ( r-l ) - 1;
    return gauss ( r-l+1 ) - 1LL;
}
 
int main () {
        
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
 
    ios_base::sync_with_stdio ( false );
    cin.tie ( 0 );
 
    int t;
    cin >> t;
    while ( t-- ) {
        cin >> n >> q;
        string s;
        cin >> s;
        pal_from = manacher ( s );
        calc ( s );
        while ( q-- ) {
            int fr, to;
            cin >> fr >> to;
            cout << ans_query ( fr, to ) << "\n";
        }
    }
 
    return 0;
}