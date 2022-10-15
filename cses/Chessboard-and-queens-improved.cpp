#include <bits/stdc++.h>
using namespace std;

const int n = 8;
char board[n][n];
bool diag1[15], diag2[15], col[8];
int cnt  = 0;

void search(int k){
  if (k == n){
    // Only way to get here is to go through a valid route
    cnt++; 
    return;
  }
  for (int i = 0; i < n; i++){
    if (col[i] || diag1[i + k] || diag2[i - k + n - 1] || board[k][i] == '*') continue;
    col[i] = diag1[i + k] = diag2[i - k + n - 1] = 1;
    search(k + 1);
    col[i] = diag1[i + k] = diag2[i - k + n - 1] = 0;
  }
}

int main(){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> board[i][j];
    }
  }  
  search(0);
  cout << cnt << endl;
}