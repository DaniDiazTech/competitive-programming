#include <bits/stdc++.h>
using namespace std;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define ll long long

ll mx = 999;
int sumdiv(int n){
  int target = mx/n; 
  return n * (target * (target + 1)) / 2;
}


int main(){
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  ll sum = 0; 

  auto start = chrono::system_clock::now();

  // Brute force
  for (int i = 1; i < 1000; i++)
    sum += (i % 3 == 0 || i % 5 == 0) ? i : 0;

  auto end = chrono::system_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << std::endl;
  cout << "Brute force: " << sum << endl;    


  start = chrono::system_clock::now();

  // Sieve-like approach  
  sum = 0;
  bool sieve[2001];
  int j = 3, k = 5;
  while (j < 1000){
    sieve[j] = 1;
    sum += j;
    j +=3;
  }
  while (k < 1000){
    if (!sieve[k])
      sum += k;
    sieve[k] = 1;
    k +=5;
  }

  end = chrono::system_clock::now();

  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << std::endl;
  cout << "Sieve : " << sum << endl;    
  
  start = chrono::system_clock::now();

  // O(1) solution
  sum = sumdiv(3) + sumdiv(5) - sumdiv(15);

  end = chrono::system_clock::now();

  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << std::endl;
  cout << "O(1) : " << sum << endl;    

  return 0;
}