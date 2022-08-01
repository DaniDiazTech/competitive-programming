// D. The clock
//  Accepted
// https://codeforces.com/contest/1692/problem/D

#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(int hh, int mm){
  string rmm = to_string(mm);
  string rhh = to_string(hh);

  if (rmm.size() < 2){
    rmm = '0' + rmm;
  }
  
  if (rhh.size() < 2){
    rhh = '0' + rhh;
  }

  reverse(rmm.begin(), rmm.end());

  if (rmm == rhh) return 1;
  return 0;
}

// Solution
void solve(){
  int hh, mm, x;
  char aux; 
  cin >> hh >> aux >> mm >> x;

  int hourdiff = x / 60;
  int mindiff = x % 60;

  set<pair<int, int>> palindromes;

  int ihh, imm; 
  ihh = imm = -1;

  while (ihh != hh || imm != mm){
    if (ihh == -1 && imm  == -1){
      ihh = hh;
      imm = mm;
    }

    
    ihh += hourdiff;
    imm += mindiff;
    

    if (imm >= 60){
      ihh += 1;
      imm -= 60;
    }
    ihh = ihh % 24;

    if (is_palindrome(ihh, imm)){
      palindromes.insert(make_pair(ihh, imm));
    }
  }

  cout << palindromes.size() << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  // Only local. Comment out if the online judge doesn't use the flag
  #ifndef ONLINE_JUDGE
      // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
  #endif

  // Testscases
  int tc;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
