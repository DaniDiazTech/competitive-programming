#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e6 + 10;
int main(){
  // Get input from file
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;

  // Use a sieve to precalculate the prime divisors of the numbers
  vector<int> a(max_n + 1);
  for (int i = 2; i < max_n; i++){
    if (a[i] == 0){
      // Means i is prime
      for (int j = i; j < max_n ; j += i){
        a[j] = i;
      }
    }
  }

  while (t--){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i =0 ; i < n; i++){
      cin >> v[i];
    }
    unordered_map<int, int> fq;
    int cnt_ones = 0;
    int mx = -1;
    for (int i  = 0 ;i < n ;i++){
      int x = v[i];
      if (x == 1) cnt_ones++;
      // Divide constantly by divisors
      while (x > 1){
        fq[x]++;
        mx = max(fq[x], mx);
        int div = a[x];
        // Don't overcount if number is prime
        if (div != x){
          fq[div]++;
          mx = max(fq[div], mx);
        }
        // Don't overcount i x is divisible multiple times by x:
        // Eg: powers of 2
      
        while (x % div == 0){
          x = x / div;
        }
      }
    }
    cout << n  - mx  << endl;
  }

  return 0;
}