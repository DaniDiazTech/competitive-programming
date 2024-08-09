#include<bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(), a.rend()
#define forn(u,n) for(int u=0;u<n;++u)
#define forns(u,i,n) for(int u=i;u<n;++u)
#define todo0(a) a,0,sizeof a
#define todom1(a) a,-1,sizeof a
#define reverso long long, vector<pair<long long,int>>, greater<pair<long long,int>>
#define mod 1000000007
#define N 100005
#define pb push_back
#define snd second
#define fst first

using namespace std;

typedef long long ll;
ll dp[801][(2*9*800)+1];
int n,q;
int rec(int indx, int dif){
    if(indx==0){
        if(dif==9*800)return 1;
        return 0;
    }
    ll &val=dp[indx][dif];
    if(val!=-1)return val;
    val=0;
    for(int i=((indx==n)?1:0);i<=9;i++){
        for(int j=((indx==n)?1:0);j<=9;j++){
            if(i==j)continue;
            val+=rec(indx-1,dif+i-j);
            val%=mod;
        }
    }
    return val;
}
int main(){
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio();
    cin.tie();
    memset(todom1(dp));
    cin>>q;
    while(q--){
        cin>>n;
        cout<<rec(n,9*800)<<"\n";
    }
    for (int i = 1;i <= 800; i++){
      cout << rec(n, 9 * 800) << ',\n';
    }
}


