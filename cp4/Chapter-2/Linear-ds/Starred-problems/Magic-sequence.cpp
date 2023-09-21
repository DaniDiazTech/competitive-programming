#include <bits/stdc++.h>
using namespace std;

void counting_sort(int a[], int n, int place, int base=10){
  int f[base] = {0}; 
  int b[n];

  for (int i =0; i < n; i++){
    f[(a[i] / place) % base]++;
  }

  for (int i = 1; i < base; i++) f[i] += f[i - 1];

  for (int i = n - 1; i>=0; i--){
    int d= (a[i] / place) % base;
    b[f[d] - 1] = a[i];
    f[d]--;
  }

  for (int i = 0; i < n; i++) a[i] = b[i];
}

void radix_sort(int a[], int n, int base = 10){
  int mx = a[max_element(a, a + n) - a];
  for (int place  = 1; mx / place > 0; place *= base){
    counting_sort(a, n, place, base);
  }
}

void solve(){

  int n; cin >>n;
  int a, b, c; cin >> a >> b >> c;
  int x,y ; cin >> x >> y; 
  int s[n];
  s[0] = a;
  b %= c;
  a %= c;
  for (int i = 1; i < n; i++){
    s[i] = (int)((int)(( (long long)s[i - 1] * (long long)(b)) % (long long)c) + a) % c;
  }

  int v = 0;

  // Speed up sort
  // Radix sort
  // max two iterations
  // radix_sort(s, n, 31622);

  // Perform sorting by hand
  int base = 31625;
  int mx = s[max_element(s, s + n) - s];
  for (int place  = 1; mx / place > 0; place *= base){
    int f[base + 10] = {0}; 
    int b[n];

    for (int i =0; i < n; i++){
      f[(s[i] / place) % base]++;
    }

    for (int i = 1; i < base; i++) f[i] += f[i - 1];

    for (int i = n - 1; i>=0; i--){
      int d= (s[i] / place) % base;
      b[f[d] - 1] = s[i];
      f[d]--;
    }

    for (int i = 0; i < n; i++) s[i] = b[i];
  }

  x %= y;
  for (int i = 0; i < n; i++){
    v = ((int) ( ( (int)(((long long)v * (long long)x) % y) + (s[i]) % y)) % y);
  }

  cout << v << "\n";
}

int32_t main(){
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
      int n; cin >>n;
  int a, b, c; cin >> a >> b >> c;
  int x,y ; cin >> x >> y; 
  int s[n];
  s[0] = a;
  b %= c;
  a %= c;
  for (int i = 1; i < n; i++){
    s[i] = (int)((int)(( (long long)s[i - 1] * (long long)(b)) % (long long)c) + a) % c;
  }

  int v = 0;

  // Speed up sort
  // Radix sort
  // max two iterations
  // radix_sort(s, n, 31622);

  // Perform sorting by hand
  int base = 31623;


  int f1[base] = {0}, f2[base] = {0};

  for (auto x: s) f1[x % base]++;
  int out[n];

  for (int i = 1; i <base; i++) f1[i] += f1[i -1];

  for (int i = n - 1; i >=0; i--){
    out[f1[s[i] % base] - 1] = s[i];
    f1[s[i] % base]--;
  }
  for(int i = 0; i < n; i++) s[i] = out[i];

  for (auto x: s) f2[x / base]++;
  int out2[n];
  for (int i = 1; i <base; i++) f2[i] += f2[i -1];

  for (int i = n - 1; i >=0; i--){
    out2[f2[s[i] / base] - 1] = s[i];
    f2[s[i] / base]--;
  }
  for(int i = 0; i < n; i++) s[i] = out2[i];

  x %= y;
  for (int i = 0; i < n; i++){
    v = ((int) ( ( (int)(((long long)v * (long long)x) % y) + (s[i]) % y)) % y);
  }

  cout << v << "\n";
  }
}