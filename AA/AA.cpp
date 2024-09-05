#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges>
using namespace std;
struct B {
    int score;
    bool flag = false;
    B()noexcept = default;
    B(const B& a)noexcept :score{ a.score }, flag{ false } {}
    auto operator<=>(const B& a)const noexcept { return score <=> a.score; }
};

int n;
int res;
vector<vector<B>> board;
bool c;
bool IsSame(const vector<vector<B>>& a, const vector<vector<B>>& b)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j].score != b[i][j].score)return false;
        }
    }
    return true;
}
void GoLeft(vector<vector<B>>& board)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            int k = j;
            if (!board[i][k].score)continue;
            while (k > 0 && board[i][k].score) {
                if (board[i][k - 1].score == board[i][k].score && !board[i][k - 1].flag) {
                    board[i][k - 1].score *= 2;
                    board[i][k].score = 0;
                    board[i][k - 1].flag = true;
                    c = true;
                    break;
                }
                else if (board[i][k - 1].score == 0) {
                    board[i][k - 1].score = board[i][k].score;
                    board[i][k].score = 0;
                }
                else
                    break;
                c = true;
                --k;
            }
        }
    }
}
void GoRight(vector<vector<B>>& board)
{
    for (int i = 0; i < n; ++i) {
        for (int j = n - 2; j >= 0; --j) {
            int k = j;
            if (!board[i][k].score)continue;
            while (k < n - 1 && board[i][k].score) {
                if (board[i][k + 1].score == board[i][k].score && !board[i][k + 1].flag) {
                    board[i][k + 1].score *= 2;
                    board[i][k].score = 0;
                    board[i][k + 1].flag = true;
                    c = true;
                    break;
                }
                else if (board[i][k + 1].score == 0) {
                    board[i][k + 1].score = board[i][k].score;
                    board[i][k].score = 0;
                }
                else
                    break;
                c = true;
                ++k;
            }
        }
    }
}
void GoUp(vector<vector<B>>& board)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            int k = j;
            if (!board[k][i].score)continue;
            while (k > 0 && board[k][i].score) {
                if (board[k - 1][i].score == board[k][i].score && !board[k - 1][i].flag) {
                    board[k - 1][i].score *= 2;
                    board[k][i].score = 0;
                    board[k - 1][i].flag = true;
                    c = true;
                    break;
                }
                else if (board[k - 1][i].score == 0) {
                    board[k - 1][i].score = board[k][i].score;
                    board[k][i].score = 0;
                }
                else
                    break;
                c = true;
                --k;
            }
        }
    }
}
void GoDown(vector<vector<B>>& board)
{
    for (int i = 0; i < n; ++i) {
        for (int j = n - 2; j >= 0; --j) {
            int k = j;
            if (!board[k][i].score)continue;
            while (k < n - 1 && board[k][i].score) {
                if (board[k + 1][i].score == board[k][i].score && !board[k + 1][i].flag) {
                    board[k + 1][i].score *= 2;
                    board[k][i].score = 0;
                    board[k + 1][i].flag = true;
                    c = true;
                    break;
                }
                else if (board[k + 1][i].score == 0) {
                    board[k + 1][i].score = board[k][i].score;
                    board[k][i].score = 0;
                }
                else
                    break;
                c = true;
                ++k;
            }
        }
    }
}
void(*Move[4])(vector<vector<B>>&) = { GoLeft,GoRight,GoUp,GoDown };

int GetMax(vector<vector<B>>& board)
{
    int max_v = -1;
    for (auto& i : board)
        for (auto& j : i) {
            max_v = max(max_v, j.score);
            j.flag = false;
        }
    return max_v;
}
vector<vector<B>> temp;
void cpy(vector<vector<B>>& a, vector<vector<B>>& b)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            a[i][j] = b[i][j];
    }
}
void go(vector<vector<B>>& b, const int N = 0)
{
    auto res2 = GetMax(b);
    auto res3 = res;
    for (int i = 0; i < 5 - N; ++i)
        res3 = res3 >> 1;
    if (res3 > res2) {
        return;
    }
    if (5 == N)
    {
        res = max(res, res2);
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        c = false;
        cpy(temp, b);
        Move[i](temp);
        if (!c)
        {
            res = max(res, GetMax(temp));
            continue;
        }
        else
            go(temp, N + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    board.resize(n, vector<B>(n));
    temp.resize(n, vector<B>(n));
    for (auto& i : board)
        for (auto& j : i)
            cin >> j.score;
    go(board);
    cout << max(res,GetMax(board));
}
