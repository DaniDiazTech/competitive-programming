// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

const int N = 1e6 + 10;

int d1[N];//d1[i] = max odd palindrome centered on i
int d2[N];//d2[i] = max even palindrome centered on i
//s  aabbaacaabbaa
//d1 1111117111111
//d2 0103010010301
void manacher(string& s){
	int l=0,r=-1,n=s.size();
  for (int i = 0; i < n; i++){
		int k=i>r?1:min(d1[l+r-i],r-i);
		while(i+k<n&&i-k>=0&&s[i+k]==s[i-k])k++;
		d1[i]=k--;
		if(i+k>r)l=i-k,r=i+k;
	}
	l=0;r=-1;
  for (int i = 0; i < n; i++){
		int k=i>r?0:min(d2[l+r-i+1],r-i+1);k++;
		while(i+k<=n&&i-k>=0&&s[i+k-1]!=s[i-k])k++;
		d2[i]=--k;
		if(i+k-1>r)l=i-k,r=i+k-1;
	}
}

void solve(){
  int n;
  cin >> n;
  int a[n];
  for (int i =0 ;i < n; i++){
    cin >> a[i];
  }
  string s;

  for (int i =0 ;i < n - 1; i++){
    s.push_back((a[i] > a[i + 1] ? 'd': 'u'));
  }
  manacher(s);

  ll ans = n;
  for (int i = 0;i <= s.size(); i++){
    ans += d2[i];
  }

  cout << ans << endl;



}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
