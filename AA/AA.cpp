#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

struct B {
    int score = 0;
    bool flag = false;
};
int n;
vector<vector<B>> b;
int res;
void init(vector<vector<B>>& board)
{
    for (auto& i : board) {
        for (auto& j : i)
            j.flag = false;
    }
}
bool CanGo(vector<vector<B>>& board,int ny,int nx)
{
    if (ny <= 0 || ny > n || nx <= 0 || nx > n)return false;
    //if (board[ny][nx].flag)return false;
    return true;
}
void GoLeft(vector<vector<B>>& board)
{
    init(board);
    //RE:
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= n ; ++j) {
            int k = j;
            //if (board[i][j].score == 0)continue;
            while (CanGo(board,i, k-1)) {
                if (board[i][k - 1].score == board[i][k].score && board[i][k - 1].flag == false)
                {
                    board[i][k - 1].score *= 2;
                    board[i][k].score = 0;
                    board[i][k - 1].flag = true;
                    board[i][k].flag = false;
                    //break;
                    //--k;
                    //continue;
                   // goto RE;
                    i = -1;
                    j = 0; continue;
                }
                else if (board[i][k - 1].score == 0)
                {
                    board[i][k - 1].score = board[i][k].score;
                    board[i][k].score = 0;
                    //--k;
                    //continue;
                }
                --k;
            }
        }
    }
}
void GoRight(vector<vector<B>>& board)
{
    init(board);
  //  RE:
    for (int i = 1; i <= n; ++i) {
        for (int j = n - 1; j >= 1 ; --j) {
            int k = j;
            //if (board[i][j].score == 0)continue;
            while (CanGo(board,i, k + 1)) {
                if (board[i][k+1].score == board[i][k].score && board[i][k + 1].flag == false)
                {
                    board[i][k+1].flag = true;
                    board[i][k + 1].score *= 2;
                    board[i][k].score = 0;
                    board[i][k].flag = false;
                    //break;
                   // continue;
                    //++k;
                   // continue;
                    //goto RE;
                    i = 0;
                    j = n; continue;
                }
                else if (board[i][k+1].score == 0)
                {
                    board[i][k + 1].score = board[i][k].score;
                    board[i][k].score = 0;
                    //++k;
                    //continue;
                }
                ++k;
                //break;
            }
        }
    }
}
void GoUp(vector<vector<B>>& board)
{
    init(board);
  //  RE:
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= n ; ++j) {
            int k = j;
            //if (board[j][i].score == 0)continue;
            while (CanGo(board, k - 1, i)) {
                if (board[k - 1][i].score == board[k][i].score && board[k - 1][i].flag == false)
                {
                    board[k - 1][i].flag = true;
                    board[k - 1][i].score *= 2;
                    board[k][i].score = 0;
                    board[k][i].flag = false;
                   // break;
                    //continue;
                    //--k;
                    //continue;
                   // goto RE;
                    i = 0;
                    j = 1; continue;
                }
                else if (board[k - 1][i].score == 0)
                {
                    board[k - 1][i].score = board[k][i].score;
                    board[k][i].score = 0;
                    //--k;
                    //continue;
                }
                --k;
                //break;
            } 
        }
    }
}
void GoDown(vector<vector<B>>& board)
{
    init(board);
   // RE:
    for (int i = 1; i <= n; ++i) {
        for (int j = n - 1; j >= 1; --j) {
            int k = j;
            //if (board[j][i].score == 0)continue;
            while (CanGo(board,k + 1, i)) {
                if (board[k + 1][i].score == board[k][i].score && board[k+1][i].flag == false)
                {
                    board[k + 1][i].flag = true;
                    board[k + 1][i].score *=2;
                    board[k][i].score = 0;
                    board[k][i].flag = false;
                    //break;
                    //continue;
                    //++k;
                    //continue;
                   // goto RE;
                    i = 0;
                    j = n; continue;
                }
                else if(board[k+1][i].score == 0)
                {
                    board[k + 1][i].score = board[k][i].score;
                    board[k][i].score = 0;
                    //++k;
                    //continue;
                }
                //break;
                ++k;
            }
        }
    }
}
int GetMax(vector<vector<B>>& board)
{
    int max_v = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            max_v = max(max_v, board[i][j].score);
        }
    }
    //cout << endl << endl;
    //for (int i = 1; i <= n; ++i) {
    //    for (int j = 1; j <= n; ++j) {
    //        cout << board[i][j].score << ' ';
    //    }
    //    cout << endl;
    //}
    return max_v;
}
function<void(vector<vector<B>>&)> f[4]{ GoLeft,GoRight,GoUp,GoDown };

void go(vector<vector<B>> board,const int N = 0)
{
    if (N == 5)
    {
        res = max(res, GetMax(board));
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        init(board);
        f[i](board);
        //init(board);
        go(board,N + 1);
       // init(board);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    b.resize(n + 1, vector<B>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> b[i][j].score;
        }
    }
    go(b);
   
    cout << res;
}