// Tell if a letter is repeated in a word
#include <bits/stdc++.h>

using namespace std;

int main() {
  string word;
  cin >> word;


  for (char ch : word) {
    int counter = 0;
    for (char ch2 : word) {
      if (ch == ch2) counter++;
      if (counter > 1) {
        cout << "yes" << endl;
        return 0;
      }
    }
  }

  cout << "no" << endl;
  return 0;
}