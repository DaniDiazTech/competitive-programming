#include <bits/stdc++.h>
using namespace std;
void tower(int n, int start, int end){
  if (n == 1){
    cout << start << " " << end << endl;
    return;
  }
  int other = 6 - (start + end);
  tower(n - 1, start, other);
  cout << start << " " << end << endl;
  tower(n - 1, other, end);
}
int main(){
  int n;
  cin >> n;
  cout << (pow(2, n)) - 1<< endl;
  tower(n, 1, 3);
}