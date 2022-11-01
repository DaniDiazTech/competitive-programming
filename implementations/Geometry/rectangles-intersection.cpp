#include <bits/stdc++.h>
using namespace std;

// Intersection of two rectangles
struct Rectangle{
  int x1, y1, x2, y2; 

  void get(){
    cin >> x1 >> y1 >> x2 >> y2;
  }

  int area(){
    return ((x2 - x1) * (y2 - y1));
  }

  int intersection(Rectangle r){
    int width = min(x2, r.x2) - max(x1, r.x1);
    int length = min(y2, r.y2) - max(y1, r.y1);
    if (width < 0 || length < 0){
      return 0;
    }
    return width * length;
  }
};
