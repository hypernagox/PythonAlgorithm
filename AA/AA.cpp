#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
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
    for (auto& row : board) {
        for (auto& cell : row) {
            cell.flag = false;
        }
    }
}
bool CanGo(const vector<vector<B>>& board, int ny, int nx)
{
    return (ny > 0 && ny <= n && nx > 0 && nx <= n);
}
void GoLeft(vector<vector<B>>& board)
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            int k = j;
            while (CanGo(board, i, k - 1) && board[i][k].score) {
                if (board[i][k - 1].score == board[i][k].score && !board[i][k - 1].flag) {
                    board[i][k - 1].score *= 2;
                    board[i][k].score = 0;
                    board[i][k - 1].flag = true;
                    break;
                }
                else if (board[i][k - 1].score == 0) {
                    board[i][k - 1].score = board[i][k].score;
                    board[i][k].score = 0;
                }
                else
                    break;
                --k;
            }
        }
    }
}
void GoRight(vector<vector<B>>& board)
{
    for (int i = 1; i <= n; ++i) {
        for (int j = n - 1; j >= 1; --j) {
            int k = j;
            while (CanGo(board, i, k + 1) && board[i][k].score) {
                if (board[i][k + 1].score == board[i][k].score && !board[i][k + 1].flag) {
                    board[i][k + 1].score *= 2;
                    board[i][k].score = 0;
                    board[i][k + 1].flag = true;
                    break;
                }
                else if (board[i][k + 1].score == 0) {
                    board[i][k + 1].score = board[i][k].score;
                    board[i][k].score = 0;
                }
                else
                    break;
                ++k;
            }
        }
    }
}
void GoUp(vector<vector<B>>& board)
{
    for (int j = 1; j <= n; ++j) {
        for (int i = 2; i <= n; ++i) {
            int k = i;
            while (CanGo(board, k - 1, j) && board[k][j].score) {
                if (board[k - 1][j].score == board[k][j].score && !board[k - 1][j].flag) {
                    board[k - 1][j].score *= 2;
                    board[k][j].score = 0;
                    board[k - 1][j].flag = true;
                    break;
                }
                else if (board[k - 1][j].score == 0) {
                    board[k - 1][j].score = board[k][j].score;
                    board[k][j].score = 0;
                }
                else
                    break;
                --k;
            }
        }
    }
}
void GoDown(vector<vector<B>>& board)
{
    for (int j = 1; j <= n; ++j) {
        for (int i = n - 1; i >= 1; --i) {
            int k = i;
            while (CanGo(board, k + 1, j)&& board[k][j].score) {
                if (board[k + 1][j].score == board[k][j].score && !board[k + 1][j].flag) {
                    board[k + 1][j].score *= 2;
                    board[k][j].score = 0;
                    board[k + 1][j].flag = true;
                    break;
                }
                else if (board[k + 1][j].score == 0) {
                    board[k + 1][j].score = board[k][j].score;
                    board[k][j].score = 0;
                }
                else
                    break;
                ++k;
            }
        }
    }
}
int GetMax(const vector<vector<B>>& board) {
    int max_v = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            max_v = max(max_v, board[i][j].score);
        }
    }
    return max_v;
}
function<void(vector<vector<B>>&)> f[4] = { GoLeft, GoRight, GoUp, GoDown };
void go(vector<vector<B>>& board, int N = 0)
{
    if (N == 5) {
        res = max(res, GetMax(board));
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        vector<vector<B>> tempBoard = board;
        f[i](tempBoard);
        init(tempBoard);
        go(tempBoard, N + 1);
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
    cout << res << '\n';
}

