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
#define pb push_back
#define ff first
#define ss second
#define mk make_pair

typedef pair<int, int> pii;

const int MAX = 1e5 + 1;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;
  
int arr[MAX];

int aux[MAX];
int aux2[MAX];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  // Only local using my exc command.
  #if LOCAL
      // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
  #endif

  // Testscases
  int n, m;
  cin >> n >> m;


  aux[0] = 0;
  aux2[n - 1] = 0;

  for (int t = 0; t < n; t++) cin >> arr[t];
  
  for (int t = 0; t < n - 1 ; t++){
    aux[t + 1] = aux[t];
    aux[t + 1] += max((int)0, (arr[t] - arr[t + 1]));
  }
  
  for (int t = n - 1; t >= 1 ; t--){
    aux2[t - 1] = aux2[t];
    aux2[t - 1] += max((int)0, (arr[t] - arr[t - 1]));
  }
 
  // for (int t = 0; t < n; t++) cout << aux[t] << " ";
  // cout << endl;
  // for (int t = 0; t < n; t++) cout << aux2[t] << " ";
  // cout << endl;
  
  for (int i = 0; i < m; i++){
    int sj, tj;
    cin >> sj >> tj;
    // cout << sj << " " << tj;
    // cout << endl;
    int ans = 0;

    tj--;
    sj--;

    if (tj < sj){
      ans = ((aux2[tj]) - (aux2[sj]));
    }
    else{
      ans = ((aux[tj]) - (aux[sj]));
    }
    cout << ans << endl;
  }

  return 0;
}
