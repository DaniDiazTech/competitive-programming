/*
What if the problem author decides to make the input a little more
problematic? Instead of an integer k at the beginning of each test case, you are now required
to sum all integers in each test case (each line).
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
  string line;
  while (getline(cin, line)){
    int s = 0;
    int ss;
    stringstream x(line);
    while (x >> ss) s+= ss;
    cout << s << endl;
  }
}
