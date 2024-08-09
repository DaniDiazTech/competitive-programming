#include<bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define forn(u,n) for(int u=0;u<n;++u)
#define todo0(a) memset(a,0,sizeof a)
#define todom1(a) memest(a,-1,sizeof a)
#define reverse int, vector<int>,greater<int>
#define mod 1000000000000
#define N 200005
#define pb push_back
#define snd second
#define fst first
using namespace std;

typedef long long ll;

int ask(string &s) {
    cout << s << endl;
    int res; cin >> res;
    return res;
}

void solve() {
    string s;
    getline(cin, s);
    const int snn = s.size();

    vector<string> names;

    string curs = "";
    for (int i = 0; i < snn; ++i) {
        if (s[i] == ' ') {
            names.push_back(curs);
            curs = "";
        }
        else {
            curs += s[i];
        }
    }
    names.push_back(curs);

    string f_name;
    string s_name;
    string f_sur;
    string s_sur;

    string rep_sname = "";
    if (names.size() == 3) {
        f_name = names[0];
        f_sur = names[1];
        s_sur = names[2];
    }
    if (names.size() == 4) {
        f_name = names[0];
        s_name = names[1];
        f_sur = names[2];
        s_sur = names[3];
        rep_sname = s_name[0];
    }

    vector<string> LDPAS;

    int idx_name = 0;
    int idx_sur = 0;

    int last_idx_sur;


    string initial= "";
    initial += f_name[0];
    initial += rep_sname;
    initial += f_sur;
    initial += s_sur[0];

    LDPAS.push_back(initial);
  // jDRodriguezR

  // substr(posicion inicial, tamano);
  // James 
    for (int i = 1;i < f_name.size(); i++){
        string s = f_name.substr(0, i + 1);
        s += rep_sname;
        s += f_sur;
        // JaDRodriguez
        LDPAS.push_back(s);

        for (int j = 0; j < min(i + 1, (int) s_sur.size()); j++){
          s += s_sur[j];
          LDPAS.push_back(s);
        }
    }

    int sizefirst = f_name.size();

    if (sizefirst < (int)s_sur.size()){
      int j = sizefirst - 1;

      string finals = f_name;
      finals += rep_sname;
      finals += f_sur;
      finals += s_sur.substr(0, sizefirst);

    // LDPAS.push_back(finals);
      j++;

      while (j < (int)s_sur.size()){
          finals += s_sur[j];
          LDPAS.push_back(finals);
          j++;
      }
    } 

  //  cout << "LDPAS: " << endl;
  //  for (auto e: LDPAS) cout << e << endl;

  //  cout << endl << endl;

    int l = 0, r = LDPAS.size() - 1;

    while (l < r) {
        int mid = l + (r - l) / 2;
        int used = ask(LDPAS[mid]);
        if (!used) r = mid;
        else l = mid + 1;
    }
    cout << "! " << LDPAS[r] << endl;
}

int main(){

    // #ifdef LOCAL
    // freopen("entra.in","r",stdin);
    // #endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    solve();
}
