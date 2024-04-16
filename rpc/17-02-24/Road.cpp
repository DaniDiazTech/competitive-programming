/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define all(s) s.begin(), s.end()
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using vi=vector<int>;
using vl=vector<ll>;
using pii=pair<int,int>;
char el = '\n';
char esp = ' ';

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<typename T>
ostream& operator<<(ostream& os, const vector<T> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

const int N = 2e5+5;
const int oo = 1e9;
int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    a--,b--;
    vector<vector<pii>> g(n);
    for(int i = 0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        g[u].pb({v,w}), g[v].pb({u,w});
    }
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    vi distances1(n, oo);
    distances1[a] = 0;
    pq.push({0, a});
    // cout<<yes<<endl;
    while(pq.size()){
        auto[dis, u]= pq.top();
        pq.pop();
        
        if(dis != distances1[u]) continue;
        for(auto[v, w]: g[u]){
            int nd = distances1[u] + w;
            if(distances1[v] > nd){
                distances1[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    
    vi distances2(n, oo);
    distances2[b] = 0;
    pq.push({0, b});
    
    while(pq.size()){
        auto[dis, u]= pq.top();
        pq.pop();
        
        if(dis != distances2[u]) continue;
        for(auto[v, w]: g[u]){
            int nd = distances2[u] + w;
            if(distances2[v] > nd){
                distances2[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    // cout<<distances1[b]<<el;
    int ans = 0;
    queue<int> q;
    q.push(a);
    vi visited(n);
    visited[a] = 1;
    set<pii> check;
    while(q.size()){
        int u = q.front();
        q.pop();
        if(u == b) break;
        
        for(auto[v,w]:g[u]){
            if(check.count({u,v}) || check.count({v,u})) continue;
            if(distances1[u] + w + distances2[v] != distances1[b]){
                ans += w;
                // cout<<u + 1<<esp<<v + 1<<esp<<w<<el;
            }
            check.insert({u,v});
            check.insert({v,u});
            if(visited[v]) continue;
            q.push(v);
            visited[v] = 1;
        }
    }
    // for(int u = 0;u<n;u++){
    //     // cout<<"u : "<<u + 1<<esp;
    //     for(auto[v,w]:g[u]){
    //         if(distances2[u]>distances1[v]) continue;
    //         cout<<"u : "<<u + 1<<esp;
    //         cout<<" v : "<<v + 1<<" w : "<<w<<el;
    //         cout<<distances1[u] <<esp<< w <<esp<< distances2[v]<<el;
    //         cout<<distances1[u] + w + distances2[v]<<el;
    //         if(distances1[u] + w + distances2[v] != distances1[b]) ans += w;
    //     }
    // }
    cout<<ans<<el;
    
}

/*
4 5 1 4
1 2 1
1 3 2
1 4 1
4 2 1
3 4 1

4 5 1 4
1 2 1
1 3 2
1 4 2
4 2 1
3 4 1
*/