#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll inf = 1e18;
// N is small
const int N = 5000;

// {distance, node}
vector<pair<ll,int>> g[N];

/*
SFPA Shortest path faster algorithm (SPFA)
Calculates single source shortest (simple) path with negative cycles.
Complexity:
Worst: O(nm)
Average: O(m)
*/

bool spfa(int s, int n, vector<ll>& d) {
    d.assign(n + 1, -inf);
    vector<int> cnt(n + 1, 0);
    vector<bool> inqueue(n + 1, false);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;

    while (!q.empty()) {

        int u = q.front();
        q.pop();
        inqueue[u] = false;

        for (auto v : g[u]) {
            int w = v.first;
            int to = v.second;

            if (d[u] + w < d[to]) {
                d[to] = d[u] + w;

                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n)
                        return false;  // negative cycle
                }
            }
        }
    }
    return true;
}