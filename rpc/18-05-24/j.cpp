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

const int MOD = 1e9 + 7;
const int mxN = 1000;

ll binexp(ll a, ll b) {
    if (b == 0LL) return 1LL;
    if (b == 1LL) return a % MOD;
    ll res = binexp(a, b / 2);
    (res *= res) %= MOD;
    if (b & 1) {(res *= a) %= MOD;}
    return res;
}
ll inv (ll x) {return binexp(x, MOD - 2);}

ll fact[mxN + 1];

void solve() {
    int N; cin >> N;

    ll ans = 0;

    for (int i = 1; i < N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            ll a_part = j - i - 1;
            ll b_part = N - 2 - a_part;

            ll contribution = fact[a_part + b_part];
            contribution = (contribution * inv(fact[a_part])) % MOD;
            contribution = (contribution * inv(fact[b_part])) % MOD;
            (ans += contribution) %= MOD;
        }
    }
    cout << ans << "\n";
}

signed main () {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("text.in", "r", stdin);
    //freopen("text.out", "w", stdout);
    fact[0] = 1;
    for (int i = 1; i <= mxN; ++i) fact[i] = (fact[i - 1] * i) % MOD;
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
