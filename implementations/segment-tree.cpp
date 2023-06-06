#include <bits/stdc++.h>
using namespace std;
// Int segment tree
// Exclusive in rx
struct segtree{
  int size;
  int NEUTRAL = 0;
  vector<int> t;
  void init(int n){
    size = 2;
    while (size < n) size *= 2;
    t.assign(2 * size, NEUTRAL);
  }

  int lc(int x){return 2 * x + 1;}
  int rc(int x){return 2 * x + 2;}

  // Actual op of st
  int merge(int x, int y){
    return x + y;
  } 
  void merge(int x){
    t[x] = merge(t[lc(x)], t[rc(x)]);
  }

  void build(vector<int> &a, int x, int lx, int rx){
    if (rx - lx == 1){
      if (lx < a.size()){
        t[x] = a[lx];
      }
      return;
    }
    int m = (lx + rx) / 2;
    build(a, lc(x), lx, m);
    build(a, rc(x), m, rx);
    merge(x);
  }

  void build(vector<int> &a){
    build(a, 0,0,size);
  }
  
  void update(int u, int v, int x, int lx, int rx){
    if (rx - lx == 1){
      t[x] = v;
      return;
    }
    int m = (lx + rx) / 2;
    if (u < m){
      update(u, v, lc(x), lx, m);
    }
    else{
      update(u, v, rc(x), m, rx);
    }
    merge(x);
  }

  void update(int u, int v){
    update(u, v, 0,0,size);
  }
  int query(int l, int r, int x, int lx, int rx){
    if (lx >= r || rx <= l) return NEUTRAL;
    if (lx >= l || rx <= r) return t[x];
    int m = (lx + rx) / 2;
    return merge(query(l,r,lc(x), lx, m), query(l,r,rc(x),m,rx));
  }
  int query(int l, int r){
    return query(l,r,0,0,size);
  }
};

// More complex segtree with items

struct item{
  int f;
  int s;
};