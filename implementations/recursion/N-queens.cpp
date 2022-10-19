#include <bits/stdc++.h>
using namespace std;

bool is_valid(int row, int column, int queens[]){
  bool ok = true;
  // Checks all the columns we have, from 0 to row (The rows we've declared)
  for (int r =0 ;  r < row; r++){
    // Check difference in col, row, and diagonal
    if (column != queens[r] && abs(r - row) != abs(queens[r] - column)){
      continue;
    }
    else{
      ok = false;
      break;
    }
  }
  return ok;
}


int search(int row, int queens[], int n){
  if (row  == n){
    for (int i = 0; i < n; i++) cout << queens[i] << ' ';
    cout << endl;
    return 1;
  }
  else{
    int total_sums = 0;
    for (int col = 0; col < n; col++){
      // Check if it's valid
      if (is_valid(row, col, queens)){
        queens[row] = col;
        total_sums += search(row + 1, queens, n);
      }
    }
    return total_sums;
  }
}
int main(){
  int n = 8;
  int row = 0;
  int queens[n];
  int ans = search(row, queens, n); 
  cout << ans << endl;
}