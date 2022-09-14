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
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define int long long int
#define double long double
#define pb push_back
#define ff first
#define ss second
#define mk make_pair

typedef pair<int, int> pii;

const int MAX = 1e6;
const int MIN = -MAX;
const int INF = LLONG_MAX;
const int MINF = LLONG_MIN;
const int MOD = 1e9 + 7;

// int arr[MAX];
int first_bracket(string str){
  return str.find_first_of('{');
}

string between_brackets(string str){
  string l = "";
  int i = first_bracket(str) + 1;
  while (str[i] != '}'){
    l+=str[i];
    i++;
  }
  return l;
}

string until_bracket(string str){
  string l = "";
  int i = 1;
  while (str[i] != '{'){
    l+=str[i];
    i++;
  }
  return l;
}
 // Solution
void solve(){
  string s;

  vector<string> v;
  vector<string> b;

  while (getline(cin, s)){
    if (s[0] == '\\'){
      string r = until_bracket(s); 
      if (r == "bibitem"){
        v.pb(s);
      }
      // continue;
    }
    istringstream iss(s);

    do{
      string word;
      iss >> word;
      if (word[0] == '\\'){
        string z = word.substr(1, 4);
        if (z == "cite"){
          string l = between_brackets(word);
          b.pb(l);
        }
      }
    }
    while (iss);
  }

  bool ok = true;

  map<int, int> correct;

  for (int i = 0; i < (int)b.size(); i++){
    string cite = b[i];
    string ccite = between_brackets(v[i]);
    if (cite == ccite){
      correct[i] = i;
      continue;
    }
    else{
      ok = false;
      for (int j = 0; j < (int)b.size(); j++){
        string newcite = between_brackets(v[j]);
        if (cite == newcite){
          correct[i] = j;
          continue;
        }
      }
    }
  }  
  
  if (ok){
    cout <<"Correct"<< endl;
  }
  else{
    cout <<"Incorrect"<< endl;
    cout << "\\begin{thebibliography}{99}" << endl; 
    for (auto x: correct){
      cout << v[x.second]  << endl;
    }
    cout << "\\end{thebibliography}" << endl; 
  }


  // for (auto x: v) cout << x << endl;
  // for (auto x: b) cout << x << endl;
}

int32_t main() {
  fastInp;

  // Only local using my exc command.
  #if LOCAL
      // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
  #endif

  // Testscases
  int tc = 1;
  // cin >> tc;

  for (int t = 1; t <= tc; t++){
    // cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
