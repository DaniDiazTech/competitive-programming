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


string morseEncode(char x)
{
    switch (x) {
    case 'a':
        return ".-";
    case 'b':
        return "-...";
    case 'c':
        return "-.-.";
    case 'd':
        return "-..";
    case 'e':
        return ".";
    case 'f':
        return "..-.";
    case 'g':
        return "--.";
    case 'h':
        return "....";
    case 'i':
        return "..";
    case 'j':
        return ".---";
    case 'k':
        return "-.-";
    case 'l':
        return ".-..";
    case 'm':
        return "--";
    case 'n':
        return "-.";
    case 'o':
        return "---";
    case 'p':
        return ".--.";
    case 'q':
        return "--.-";
    case 'r':
        return ".-.";
    case 's':
        return "...";
    case 't':
        return "-";
    case 'u':
        return "..-";
    case 'v':
        return "...-";
    case 'w':
        return ".--";
    case 'x':
        return "-..-";
    case 'y':
        return "-.--";
    case 'z':
        return "--..";
    case '1':
        return ".----";
    case '2':
        return "..---";
    case '3':
        return "...--";
    case '4':
        return "....-";
    case '5':
        return ".....";
    case '6':
        return "-....";
    case '7':
        return "--...";
    case '8':
        return "---..";
    case '9':
        return "----.";
    case '0':
        return "-----";
    default:
        cerr << "Found invalid character: " << x << ' '
             << endl;
        exit(0);
    }
}

string to_morse(string s){
  string result = "";
  for (int i = 0; i < (int)s.size(); i++){
    result += morseEncode(s[i]);
  }

  return result;
}

 // Solution
void solve(){

  string valid = "";
  for (char i = 'a'; i <= 'z'; i++) valid += i;
  for (char i = '0'; i <= '9'; i++) valid += i;

  string line = "";
  // string buffer;

  while (getline(cin, line)){
    string s = "";
    for (char x: line){
      char z = tolower(x);
      
      if (valid.find(z) != string::npos){
        s += z;
      }
    }
    if (s == ""){
      cout << "NO" << endl;
      continue;
    }
    // cout << "Without: " << s  << endl;
    s = to_morse(s);
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    // cout << s << " AND " << reversed << endl;
    cout << ((s == reversed) ? "YES": "NO") << endl; 
    // getline(cin, buffer);
  }
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
