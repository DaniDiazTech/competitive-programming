#include <bits/stdc++.h>
using namespace std;

void search(int k, int n, string s, vector<string> &v){
  if (k == n + 1){
    v.push_back(s);
  }
  else{
    // include 1
    s.push_back('1');
    search(k + 1, n, s, v);
    // not include 1
    s.pop_back();
    s.push_back('0');
    search(k + 1, n, s, v);
  }
}

int main(){
  #if LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int n; cin >> n;
  string s = "";
  vector<string> v;
  search(1, n, s, v);


  sort(v.begin(), v.end());
  vector<int> visited(v.size() + 10);
  // Brute force all the way up!
  for (int i = 0; i < (int)v.size(); i++){
    // cout << "CURRENT: " << v[i] << " POSSIBLE: ";
    // for (int p = 0; p < v.size(); p++){
    //   if (!visited[p]) cout << v[p] << " ";
    // }
    // cout << endl;
    if (!visited[i]){
      cout << "DEBUG " << v[i] << endl;
    }
    else{
      continue;
    }
    visited[i] =1;



    for (int j = 0; j <  (int)v.size(); j++){
      cout << "CURRENT: " <<  v[i] << " " << v[j] << endl;
      if (!visited[j]){
        int diff = 0;
        for (int k = 0; k < n; k++){
          if (diff > 1) break;
          if (v[i][k] != v[j][k]) diff++;
        }
        if (diff == 1){
          visited[j] = 1;
          cout << v[j] << endl;
          break;
        }
      }
    }
  }

}