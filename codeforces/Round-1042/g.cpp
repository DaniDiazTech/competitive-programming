// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";

int MSB(int x){
  if (x == 0) return 0;
  int y = 1;
  int ans= 0;
  while (y <= x){
    if (y & x){
      ans = y;
    }
    y *= 2;
  }
  return ans;
}

int MSBind(int x){
  if (x == 0) return -1;
  int y = 1;
  int ans= 0;
  int z = 0;
  while (y <= x){
    if (y & x){
      ans = z;
    }
    y *= 2;
    z++;
  }
  return ans;
}

const int N = 32;

int f[N];
ll contrib[N], mulcontrib[N];


void solve(){
  int n, k;
  cin >> n >> k;

  vector<ll> a;
  for (int i =0 ;i < n; i++){
    int x; cin >> x;
    a.push_back(x);
  }
  sort(a.rbegin(), a.rend());

  ll ans = 1;

  while (k){
    ll mn = a.back();
    a.pop_back();

    ll work = mn;

    if (mn > 31){
      ans *= (ll)mn;
      ans %= mod;
      k--;

      for (int i  = 31 ; i >= 1; i--){
        a.push_back(i);
      }
      continue;
    }


    int msb = MSB(k);
    int ind = MSBind(k);
    
    // two options: Consume partially, or consume all of m
    if (ind + 1 >= work){
      // consume totally
      ans *= contrib[work];
      ans %= mod;
      
      k -= (1 << (work - 1));
    }
    else{
      // ind + 1 < work
      // consume partially
      // only inserts up to 30 * (31)

      ans *= work;
      ans %= mod;
      k--;

      msb = MSB(k);
      ind = MSBind(k);


      if (ind ==-1){
        continue;
      }

      ans *= mulcontrib[ind];
      ans %= mod;

      k -= msb;
      k++;


      for (int i = work - 1; i > ind ; i--){
        a.push_back(i);
      }
    }
  }

  cout << ans << endl;
}

void brute(int k, vector<ll> &v){
  sort(v.rbegin(), v.rend());
  ll ans = 1;
  while (k){
    ll m = v.back();
    v.pop_back();
    k--;
    ans *= m;
    ans %= mod;
    for (int i = m - 1; i >= 1; i--){
      v.push_back(i);
    }
  }

  cout << "BRUTE: " << ans << endl;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif


  f[1] = 1;
  contrib[1] = 1, mulcontrib[1] = mulcontrib[0] = 1;

  for (int i = 2; i < N; i++){
    f[i]= f[i - 1] * 2;
    contrib[i] = (ll)i;
    for (int j = 2; j < i; j++){
      contrib[i] *= contrib[j];
      contrib[i] %= mod;
    }

    mulcontrib[i] = contrib[i];
    for (int j = 2; j < i; j++){
      mulcontrib[i] *= contrib[j];
      mulcontrib[i] %= mod;
    }
  }

  // return 0;

  // for (int i = 1; i < N; i++){
  //   cout << f[i] << " ";
  // }
  // cout << endl;
  // for (int i = 1; i < N; i++){
  //   cout << contrib[i] << " ";
  // }
  // cout << endl;
  

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
