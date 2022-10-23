#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define fast  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

ll pown(ll x,ll y)   
{
    x=1;
    while(y--)
    x=x*10;
    return x;
}

void fun(ll k)
{
  ll s=0,n=1,lower_value=0,num,rem;
  while(1)
  {
      lower_value=s;
      s=s+9*n*pown(10,n-1);
      if(k<=s)
      break;
      else
      n++;
  }
  
  num=pown(10,n-1)+(k-(lower_value+1))/n;
  rem=(k-(lower_value+1))%n;
  string b=to_string(num);
  cout<<b[rem]<<endl;
}
 
int main()
{
  fast
   ll q,k;
    cin>>q;
    while(q--)
    {
        cin>>k;
        fun(k);
    }
    return 0;
}
