#include <bits/stdc++.h>
using namespace std;

#define ll long long
int lsb(ll x){
  return 1 <<  (__builtin_ctzll(x));
}

int msb(ll x){
  return 1 << (63 - (__builtin_clzll(x)));
}

int main(){
  cout << "1.\nRemainder modulo N power of 2" << endl;
  int x = 7, n = 4;
  cout << (x & (n -1)) << " = " << (x % n) << endl;

  cout << "2.\nDetermine if S is power of 2" << endl;
  int s = 32;

  cout << s << " is Power of 2? " << (lsb(s) == msb(s) ? "YES" : "NO") << endl;

  cout << "3.\nTurn off last one in S\n";
  s = 40;
  cout << s << " -> " << (s ^ lsb(s)) << endl;

  cout << "4.\nTurn on the last zero in S\n";
  s = 41;

  cout << s << " -> " << (s | (s + 1)) << endl;

  cout << "5.\nTurn off last consecutive run of ones in S" << endl;
  s = 39;
  cout << s << " -> " << (s & (s + 1)) << endl;

  cout << "6.\nTurn on the last consecutive zeroes in S" << endl;
  s = 36;
  cout << s <<  " -> " << (s | (s - 1)) << endl;

}