// Made by Daniel Diaz (@Danidiaztech)
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const string yes = "YES", no = "NO";
// 0 1 .. 9
int vis[10];
void solve(){
  int n, m;
  cin >> n >> m;
  // priority
  deque<pair<int,int>> q; // Lo mismo que la lista enlazada
  for (int i = 1; i<=9; i++)vis[i] = 0;
  for (int i =0 ;i < n; i++){
    int x; cin >> x;
    vis[x]++; // Agrego a la frequencia la prioridad
    // Pair<int,int> p;
    // p.first = x;
    // p.second = i;
    q.push_back({x, i});
  }

  int cnt = 0;
  // head == null

  while (q.size()){
    auto p = q.front();
    q.pop_front();


    int x = p.first, j = p.second; 
    bool f = 1;


    // Miro la frequencia y si existe alguna prioridad mayor todavia en la lista
    for (int l = x + 1; l <= 9; l++){
      if (vis[l] >= 1){
        f = 0;
        break;
      }
    }

    if (f){
      vis[x]--;
      cnt++;
      if (j == m){
        break;
      }
    }
    else{
      q.push_back(p);
      // En la lista enlazada
      // newnode = {prioridad, indice actual}
      // tail->next= newnode
      // newnode->prev = prev
      // tail = newnode
    }
  }
  cout << cnt << endl;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

  #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int tc = 1;
  cin >> tc;

  for (int t = 1; t <= tc; t++){
    solve();
  }
}
