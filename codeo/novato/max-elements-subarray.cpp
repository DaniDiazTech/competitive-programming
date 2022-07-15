#include <bits/stdc++.h>

using namespace std;

int main() {
  #ifndef LOCAL
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
  #endif
  int n, l, r, c;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];

  cin >> c;

  for (int i = 0; i < c; i++) {
    cin >> l >> r;
    int building, maxh;
    building = maxh = 0;
    for (int j = l; j < r + 1; j++) {
      if (arr[j] > maxh) {
        maxh = arr[j];
        building = j;
      }
    }
    cout << building << endl;
  }


  return 0;
}