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

map<string, bool> upd;
map<char, bool> valcb;
map<bool, char> valbc;

const int mxN = 1000;
//string combs[8] = {"111", "110", "101", "100", "011", "010", "001", "000"};
string combs[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};

void solve() {
    valcb['X'] = true;
    valcb['.'] = false;
    valbc[true] = 'X';
    valbc[false] = '.';

    int rule, K; cin >> rule >> K;

    for (int i = 0; i < 8; ++i) {
        upd[combs[i]] = rule & 1;
        rule >>= 1;
    }

    string s; cin >> s;

    const int n = s.size();
    while (K--) {
        // iteration
        string new_s = s;
        for (int i = 0; i < n; ++i) {
            string state;
            // Left
            if (i - 1 < 0) state += '0';
            else state += (s[i - 1] == '.' ? '0' : '1'); ;
            // Mid
            state += (s[i] == '.' ? '0' : '1');
            // Right
            if (i + 1 >= n) state += '0';
            else state += (s[i + 1] == '.' ? '0' : '1');
            //cout << "STATE: " << state << endl;

            new_s[i] = valbc[upd[state]];
        }
        s = new_s;
        cout << new_s << "\n";
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
