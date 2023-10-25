// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
// U D L R 
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};


int n, m;

int32_t main() {
    
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    string x;
    cin >> x;
    ll b, c, s;
    b = c = s = 0;
    
    for (int i = 0 ;i < x.size() ; i++){
        b += x[i]== 'B';
        c += x[i]== 'C';
        s += x[i]== 'S';
    }
    
    ll nb, ns, nc;
    cin >> nb >>  ns >> nc;
    
    ll pb, ps, pc;
    cin >> pb >> ps >> pc;
    
    ll l = 0 , r = 2 * 1e12;
    ll argent; cin >> argent;
    while (l + 1 < r){
        ll m = (l + r) / 2;
        
        ll a1 = max(0ll, (m * b - nb) ) * pb;
        ll a2 = max(0ll, (m * s - ns) ) * ps;
        ll a3 = max(0ll, (m * c - nc) ) * pc;
        
        ll sum = a1 + a2 + a3;
        if (sum <= argent){
            l = m;
        }
        else r =m;
    }
    
    cout << l << endl;
    
    return 0;
}