#include <bits/stdc++.h>
using namespace std;
void print(vector<char> a){
  for (auto x: a) cout << x << ' ';
  cout << "\n";
}
int main(){
  vector<char> a(10);
  for (char ch = 'a';ch <= 'j'; ch++) a.push_back(ch);
  int i = 0;
  do{
    i++;
    // Dangerous xd
    print(a);
  } while (next_permutation(a.begin(), a.end()));
  cout << i;
}