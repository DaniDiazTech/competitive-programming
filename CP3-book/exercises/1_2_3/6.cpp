#include <bits/stdc++.h>
using namespace std;
int main(){
  int n = 1000000;
  // cin >> n;
  vector<int> a(n);
  for (int  i = 0, j = 1; i < n; i++, j+=2) a[i] = j;
  int search; 
  cin >> search;
  // bs
  int l = 0, r =n -1;
  int ans  = -1;
  int i = 0;
  while (l < r){
    i++;
    int mid = (l + r) >> 1;
    if (a[mid] == search) {
      ans  = mid; break;
    }
    if (a[mid] > search) r = mid; 
    else l = mid + 1;
  }
  // int ans  = lower_bound(a.begin(), a.end(), search) - a.begin();
  if (ans == -1) cout << "Not found " << ans << " Attempts: " << i << endl; 
  else cout << "Found at index: " <<  ans << " Attempts: " << i << endl;
}