#include <iostream> // cin/cout
#include <algorithm> //reverse


int main(){
  // Standard library solution
  std::string str = "Hello there";
  // Reverse in place
  std::reverse(str.begin(), str.end());

  for (int i = 0; i < str.size(); i++){
    std::cout << str[i];
  }
}