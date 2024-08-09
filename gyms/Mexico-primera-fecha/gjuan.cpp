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
set<int>unico;
int n;
int x;
int main(){
    #ifdef LOCAL
    freopen("entra.in","r",stdin);
    #endif
    ios_base::sync_with_stdio();
    cin.tie();
    cin>>n;
    forn(i,n){
        cin>>x;
        unico.insert(x);
    }
    vector<int>game;
    int cnt=0;
    if(unico.size()){
        for(auto it:unico)game.pb(it);
    }
    for(int i=0;i<game.size();i++){
        if(game[i]!=i+1)break;
        cnt++;
    }
    if(game.size()==1)cout<<"Alicius\n";
    else{
        cout<<((cnt%2)?"Bobius\n":"Alicius\n");
    }
}


