#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
// using namespace __gnu_pbds;
// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef unsigned long long ull;
//typedef __int128_t ell;
//typedef __uint128_t uell;

#define delay(time) this_thread::sleep_for(std::chrono::seconds(time));
#define pb push_back
#define mp make_pair
#define FOR(n) for (int i = 0; i < n; ++i)
#define FORj(n) for (int j = 0; j < n; ++j)

void solve() {
    ll area; cin >> area;
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<int, bool> mp;

    for (int i = 0; i < n; ++i) {
        ll x = (ll)a[i];
        if (area % x == 0) {
            if (mp[area / x]) {
                cout << min(x, area / x) << " " << max(x, area / x) << "\n";
                return;
            }
            mp[x] = true;
        }
    }
}

signed main () {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("text.in", "r", stdin);
    //freopen("text.out", "w", stdout);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
