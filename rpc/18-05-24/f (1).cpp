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
vector<int>per,val;
map<int,int>frec;
int n,x;
int visi[14];
ll ans;
void rec(int indx){
    if(indx==11){
        ll cc=0;
        cc+=frec[1];
        int ult=-1;
        for(int i=0;i<per.size();i++){
            if(ult!=-1)cc+=__gcd(ult,per[i]);
            if(frec[per[i]]==0)continue;
            if(per[i]==2){
                int pot[4]={2,4,8,16};
                int last=-1;
                for(int j=0;j<4;j++){
                    if(frec[pot[j]]==0)continue;
                    if(last!=-1){
                        cc+=__gcd(last,pot[j]);
                    }
                    cc+=pot[j]*(frec[pot[j]]-1);
                    last=pot[j];
                }
                ult=last;
            }
            else if(per[i]==3){
                int pot[2]={3,9};
                int last=-1;
                for(int j=0;j<2;j++){
                    if(frec[pot[j]]==0)continue;
                    if(last!=-1){
                        cc+=__gcd(last,pot[j]);
                    }
                    cc+=pot[j]*(frec[pot[j]]-1);
                    last=pot[j];
                }
                ult=last;
            }
            else{
                cc+=per[i]*(frec[per[i]]-1);
                ult=per[i];
            }
        }
        int prim[4]={11,13,17,19};
        for(int i=0;i<4;i++){
            if(frec[prim[i]]==0)continue;
            cc+=__gcd(ult,prim[i]);
            cc+=prim[i]*(frec[prim[i]]-1);
            ult=prim[i];
        }
        ans=max(ans,cc);
    }
    else{
        for(int i=0;i<11;i++){
            if(visi[i])continue;
            visi[i]=1;
            per.pb(val[i]);
            rec(indx+1);
            per.pop_back();
            visi[i]=0;
        }
    }
}
int main(){
    #ifdef LOCAL
    freopen("entra.in","r",stdin);
    #endif
    ios_base::sync_with_stdio();
    cin.tie();
    memset(todo0(visi));
    val.pb(2),val.pb(3),val.pb(5),val.pb(6),val.pb(7),val.pb(10);
    val.pb(12),val.pb(14),val.pb(15),val.pb(18),val.pb(20);
    cin>>n;
    forn(i,n){
        cin>>x;
        frec[x]++;
    }
    ans=0;
    rec(0);
    cout<<ans<<"\n";
}



