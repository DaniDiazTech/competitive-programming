// Find if a matrix n x n is a magic square
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, h, d, d2, v, horizontal, vertical, LIM;
  cin >> n;

  int arr[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  // -1000 <= Ai, j <=  1000
  LIM = 1000 * n + 1;

  horizontal = vertical = LIM;

  for (int i = 0; i < n; i++) {
    h = 0;
    v = 0;
    // horizontal / rows 
    for (int j = 0; j < n; j++) {
      h += arr[i][j];
      v += arr[j][i];
    }
    if (horizontal == LIM) {
      horizontal = h;
    }
    else if (h != horizontal) {
      cout << "No";
      return 0;
    }
    // Vertical / columns
    if (vertical == LIM) {
      vertical = v;
    }
    else if (v != vertical) {
      cout << "No";
      return 0;
    }
  }
  d = 0;
  d2 = 0;

  // diagonal
  for (int j = 0; j < n; j++) {
    d += arr[j][j];
  }
  if (d != horizontal) {
    cout << "No";
    return 0;
  }

  // diagonal 2
  int rowindex = 0;
  for (int j = n - 1; j > -1; j--) {
    d2 += arr[rowindex][j];
    rowindex += 1;
  }
  if (d2 != horizontal) {
    cout << "No";
    return 0;
  }
  // cout << horizontal << vertical << d << d2;

  cout << "Yes";
  return 0;
}