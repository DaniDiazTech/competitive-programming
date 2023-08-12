#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define   ll long long 
 
using namespace std;
 
string x,y,a,b,c,d;
 
int main(){
    #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin>>x>>y;
    a=b=c=d="";
    for(int i=0;i<x.size()/2;i++){
        a+=x[i];
    }
    for(int i=x.size()/2;i<x.size();i++){
        b+=x[i];
    }
    for(int i=0;i<y.size()/2;i++){
        c+=y[i];
    }
    for(int i=y.size()/2;i<y.size();i++){
        d+=y[i];
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    sort(all(d));
    if (x == y){
      cout << "YES\n";
    }
    else{
      if((x.size() & (x.size() - 1)) != 0){
        cout << "NO\n";
      }
      else{
          if (((a == c) && (b == d)) || ((a == d) && (b == c))) cout << "YES\n";
          else cout<<"NO\n";
      }
    }
} 