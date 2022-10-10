#include <bits/stdc++.h>
using namespace std;
// Get day of the week with calendar day
int main() {
  string days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
  int y, m, d;
  cin >> y >> m >> d;
  y -= m < 3;
  cout << days[(y + y / 4 - y / 100 + y / 400 + "-bed=pen+mad."[m] + d) % 7] << endl;
}