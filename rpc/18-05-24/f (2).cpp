#include<bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(), a.rend()
#define forn(u,n) for(int u=0;u<n;++u)
#define forns(u,i,n) for(int u=i;u<n;++u)
#define todo0(a) a,0,sizeof a
#define todom1(a) a,-1,sizeof a
#define reverso long long, vector<pair<long long,int>>, greater<pair<long long,int>>
#define mod 998244353
#define N 100005
#define pb push_back
#define snd second
#define fst first

using namespace std;

typedef long long ll;
map<int,int>frec;
int n,x;
ll dp[2097160][21];
long long rec(int cur, int y){
    ll &w=dp[cur][y];
    if(cur==0)return 0;
    if(w!=-1)return w;
    w=0;
    forns(i,1,21){
        if(cur&(1<<i)){
            w=max(w,__gcd(i,y)+((frec[i]-1)*i)+rec(cur-(1<<i),i));
        }
    }
    return w;
}
int main(){
    #ifdef LOCAL
    freopen("entra.in","r",stdin);
    #endif
    ios_base::sync_with_stdio();
    cin.tie();
    cin>>n;
    ll num=0;
    forn(i,n){
        cin>>x;
        frec[x]++;
        if(frec[x]==1)num+=(1<<x);
    }
    memset(todom1(dp));
    ll ans=0;
    forns(i,1,21){
        if(num&(1<<i)){
//            cout<<num<<" "<<i<<"\n";
            ans=max(ans,rec(num-(1<<i),i)+((frec[i]-1)*i));
        }
    }
    cout<<ans<<"\n";
}


