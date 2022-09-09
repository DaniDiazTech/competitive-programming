/*
Problem name:
Algorithm or Logic:
Complexity:
Link:
More info:
*/

#include <bits/stdc++.h>

using namespace std;

// Templates
#define endl '\n'
#define int long long int
#define double long double
#define MAX LLONG_MAX
#define MIN LLONG_MIN


int calc_val(vector<int> v){
  int x= 0;

  for (auto i: v){
    if (x < i){
      x += i;
    }
    else x = 0;
  }

  return x;
}

// Solution
void solve()
{
  int n;
  cin >> n;
  vector<int> v = {};

  vector<int> reserved = {};

  if (n >= 6 && (n - 1) % 3)
  {
    reserved = {1, 2, n - 3, n};
    for (int i = 1; i <= n; i++)
    {
      bool flag = true;
      for (auto x : reserved)
      {
        if (i == x)
        {
          flag = false;
          break;
        }
      }
      if (flag) v.push_back(i);
    }

    v.insert(v.end(), reserved.begin(), reserved.end());
  }
  else
  {
    reserved = {1, n - 1, n};
    for (int i = 1; i <= n; i++)
    {
      bool flag = true;
      for (auto x : reserved)
      {
        if (i == x)
        {
          flag = false;
          break;
        }
      }
      if (flag) v.push_back(i);
    }

    v.insert(v.end(), reserved.begin(), reserved.end());
  }

  for (auto x: v){
    cout << x << " ";
  }
  // cout << endl <<  calc_val(v);
  cout << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// Only local using my exc command.
#if LOCAL
  // For getting input from input.txt file
  freopen("input.txt", "r", stdin);

  // Printing the Output to output.txt file
  freopen("output.txt", "w", stdout);
#endif

  // Testscases
  int tc;
  cin >> tc;

  for (int t = 1; t <= tc; t++)
  {
    // cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
