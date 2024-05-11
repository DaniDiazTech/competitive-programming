// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";


#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;


struct comp{

  bool operator() (const pair<ll, string> &p1, const pair<ll, string> &p2) {
    if (p1.first != p2.first) return p1.first > p2.first;
    return p1.second < p2.second;
  }

};

typedef tree<
pair<ll, string>,
null_type,
comp,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

void solve(){
  ordered_set t;
  // t.insert({1, "ab"});

  // auto p = *t.find({1, "ab"});
  // cout << p.first << " " << p.second << endl;

  // t.erase({1, "ab"});  

  // p = *t.find({1, "ab"});
  // cout << p.first << " " << p.second << endl;

  int n, q; cin >> n >> q;
  map<string , ll> salary;
  for (int i = 0;i < n; i++){
    string name;
    ll sal;
    cin >> name >> sal;
    salary[name] = sal;
    t.insert({sal, name});
  }

  while (q--){
    int x; cin >> x;
    if (x == 2){
      auto p = *t.find_by_order(0); 
      cout << p.second << " " << p.first << '\n';
      t.erase(p);
    }
    else{
      string name;
      ll r;
      cin >> name >> r; 
      auto p = *t.find({salary[name], name});
      t.erase(p);
      p.first += r;
      salary[name] = p.first;
      t.insert(p);
    }
  }
  
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
