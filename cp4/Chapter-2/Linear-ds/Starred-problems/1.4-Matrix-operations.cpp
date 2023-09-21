#include <bits/stdc++.h>
using namespace std;

int main(){
  int n = 5;
  int a[n][n];
  cout << "Original: "  << endl;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      a[i][j] = rand() % 10;
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

  cout << "1: Rotate counter clockwise" << endl;

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << a[j][(n - i - 1)] << " ";
    }
    cout << endl;
  }
  
  cout << "2: Traspose" << endl;

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << a[j][i] << " ";
    }
    cout << endl;
  }
  
  cout << "3: Rotate x" << endl;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << a[(n - i - 1)][j] << " ";
    }
    cout << endl;
  }
  cout << "3: Rotate y" << endl;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << a[i][(n - j - 1)] << " ";
    }
    cout << endl;
  }
  

}