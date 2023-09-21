#include <bits/stdc++.h>
using namespace std;
int main(){
  int n = 10;
  tuple<int, string, string> a[n];
  for (int i = 0; i < n; i++){
    get<0>(a[i]) = rand() % 2;
    get<1>(a[i]) = "Last name " + to_string(rand() % 3);
    get<2>(a[i]) = "First name " + to_string(rand() % 8);
  }
  // sort ascending age, descending last name, ascending first name
  sort(a, a+ n,[](const tuple<int, string, string>&a, const tuple<int,string,string> &b){
    if (get<0>(a) == get<0>(b)){
      if(get<1>(a) == get<1>(b)){
        return get<2>(a) < get<2>(b);
      } 
      else{
        return get<1>(a) > get<1>(b);
      }
    }
    else return get<0>(a) < get<0>(b);
  });

  for (int i =0; i < n; i++){
    cout << get<0>(a[i]) << " " << get<1>(a[i]) << " " << get<2>(a[i]) << endl;
  }


  // 2.
  n = 15;
  pair<int,int> b[n];
  for (int i =0; i < n; i++){
    b[i] = {(rand() % 123) + 1, (rand() % 120) + 1};
  }
  sort(b, b + n, [](const pair<int, int> &p1, const pair<int, int> &p2){
    return p1.first * p2.second < p2.first * p1.second;
  });
  cout << "Fractions\n";
  for (int i =0; i < n; i++){
    cout << b[i].first << " " << b[i].second << endl;
  }
}