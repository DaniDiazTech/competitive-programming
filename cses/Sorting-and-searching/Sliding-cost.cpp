// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define forn(i, n) for (int i = 0; i < n; i++) // for in range in python
#define FOR(i, a, b) for (int i = a; i < b; i++) // for in range in python
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair

typedef pair<int, int> pii;

const int MAX = 1e6;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

int N, K; 
int sumLow = 0, sumUpper = 0;
multiset<int> low;
multiset<int> upper;

void insert(int val){
  int maxLow = *low.rbegin();
  if (maxLow < val){
    // insert in the up array
    upper.insert(val);
    sumUpper += val;
    if (upper.size() > K / 2){
      int move = *upper.begin();

      low.insert(move);
      sumLow += move;
      upper.erase(upper.find(move));
      sumUpper -= move;
    }
  }
  else{
    // Insert it in the lower half
    low.insert(val);
    sumLow += val;
    if (low.size() > (K + 1) /2){
      int move = *low.rbegin(); 
      upper.insert(move);
      sumUpper += move;
      low.erase(low.find(move));
      sumLow -= move;
    }
  }
}

void erase(int val){
  if (upper.find(val) != upper.end()){
    upper.erase(upper.find(val));
    sumUpper -= val;
  }
  else{
    low.erase(low.find(val));
    sumLow -= val;
  }
  // always keep lower populated 
  if (low.empty()){
    int move = *upper.begin();
    low.insert(move);
    sumLow += move;
    upper.erase(upper.find(move));
    sumUpper -= move;
  }
}

int med_odd(){
  if (K & 1){
    return *low.rbegin();
  }
  else return 0;
}

int32_t main() {
  fastInp;
  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  cin >> N >> K;
  int a[N];
  forn(i, N) cin >> a[i];
  low.insert(a[0]);
  sumLow += a[0];
  for (int i = 1; i < K; i++){
    insert(a[i]);
  }
  cout << sumUpper - sumLow + med_odd() << " ";

  for (int i = K; i < N ; i++){
    if (K == 1){
      // There must always be an element in low
      insert(a[i]);
      erase(a[i - K]);
    }
    else{
      erase(a[i - K]);
      insert(a[i]);
    }
    cout << sumUpper - sumLow + med_odd() << " ";
  }
  return 0;
}
