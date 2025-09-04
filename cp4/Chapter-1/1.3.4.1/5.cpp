#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<vector<int>> birthdays;
  for (int i=0 ;i <n; i++){
    int dd, mm, yyyy; cin >> dd >> mm >> yyyy;
    birthdays.push_back({dd,mm,yyyy});
  }
  sort(birthdays.begin(), birthdays.end(), [&](vector<int>&a, vector<int>&b){
    if (a[1] == b[1]){
      if (a[0] == b[0]){
        return a[2] < b[2];
      }
      else return a[0] < b[0];
    }
    else return a[1] < b[1];
  });

  cout << "FINAL ORDER:" << endl;
  for (auto bd: birthdays){
    bool f= 0;
    for (auto x: bd){
      if (f)cout << '/';
      f = 1;
      cout << x;
    }
    cout << endl;
  }
  /*
  Tested input:
  7 
  4 1 2004
  14 12 2004 
  15 2 2012
  20 12 2007
  18 7 2001
  20 8 2022
  14 12 2009 

  Out:
  FINAL ORDER:
  4/1/2004
  15/2/2012
  18/7/2001
  20/8/2022
  14/12/2004
  14/12/2009
  20/12/2007
  */
}