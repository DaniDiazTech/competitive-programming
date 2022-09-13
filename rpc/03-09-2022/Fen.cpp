#include <bits/stdc++.h>
using namespace std;

#define fastInp \
  cin.tie(0);   \
  cout.tie(0);  \
  ios_base::sync_with_stdio(0);

int main()
{
  // fastInp;  // Only local using my exc command.
  #if LOCAL
      // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
  #endif

  string board;
  bool flag = false;
  while (cin >> board)
  {
    if (flag)
      printf("\n");
    char rboard[8][8];
    int i = 0, j = 0;
    for (int s = 0; s < (int)board.size(); s++)
    {
      if (j >= 8)
      {
        j -= 8;
        i++;
      }
      switch (board[s])
      {
      case 'r':
      case 'R':
      case 'p':
      case 'P':
      case 'n':
      case 'N':
      case 'B':
      case 'b':
      case 'K':
      case 'k':
      case 'Q':
      case 'q':
        rboard[j++][i] = board[s];
        break;
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
        for (int t = 0; t < board[s] - 48; t++)
        {
          rboard[j++][i] = '0';
        }
        break;
      default:
        break;
      }
    }
    for (i = 0; i < 8; i++)
    {
      for (j = 7; j >= 0; j--)
      {
        if (j  == 0){
          printf("%c", rboard[i][j]);
        }
        else{
          printf("%c ", rboard[i][j]);
        }
      }
      printf("\n");
    }
    flag = true;
  }
  return 0;
}
