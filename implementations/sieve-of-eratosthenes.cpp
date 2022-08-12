/* Sieve of Eratosthenes

Compute all the prime numbers up to n

Complexity 

1. Create an array or bool vector with n + 1 size
2. All the values of the array start at true
3. Iterate over the array starting at 2, and perform the sifting up to sqrt(n)
4. Check if arr[i] is prime. As it starts with the smallest prime
   number (2) this condition is always true
5. Iterate over the array starting at j = i * i (i squared), and increase by i,
   turning all the values multiples of i, greater than i squared false.

*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"

vector<bool> sieve(int n){
  // All i start as true
  vector<bool> is_prime(n + 1, true);

  // Turn 0 and 1 into not primes
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i * i <= n; i++){
    if (is_prime[i]){
      for (int j = i * i; j <= n; j += i){
        is_prime[j] = false;
      }
    }
  }
  
  return is_prime;
}

int32_t main(){
  int n = 200;
  auto v = sieve(n);

  for (int i = 1; i <= n; i++){
    if (v[i]) cout << i << " ";
  }
} 