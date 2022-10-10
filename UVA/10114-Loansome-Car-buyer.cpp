#include <bits/stdc++.h>
using namespace std;
int main(){
  #if LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  string line;
  int cnt = 1;
  while (getline(cin, line)){
    stringstream x(line);
    int months, dep;
    double down, loan, car;
    x >> months >> down >> loan >> dep;
    if (months < 0) break;
    car  = (loan + down);
    // owes less than the car value
    vector<pair<int, double>> a;
    for (int i = 0; i < dep; i++){
      string l;
      getline(cin, l);
      stringstream o(l);
      int m; double n; o >> m >> n;
      a.push_back({m, n}); 
    }
    double cur_deg = 0;
    int ans = 0;
    double topay = loan / months;
    for (int i= 0, j = -1; i <= months; i++){
      if (j < (int)a.size()){
        if (i == a[j + 1].first){
          cur_deg = a[j+1].second;
          j++;
        }
      }
      car = (car * (1 - cur_deg));
      if (i >= 1) loan -= topay;
      if (loan < car ){
        ans = i;
        cout << ans << " month" << ((ans != 1)?"s":"") << endl;
        break;
      }
    }
    cnt++; 
  }
}