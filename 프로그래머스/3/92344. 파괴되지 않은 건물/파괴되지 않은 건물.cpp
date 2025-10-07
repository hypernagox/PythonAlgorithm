#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int delta_board[1002][1002];
int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    int answer = board.size() * board.back().size();
    for (const auto& v : skill)
    {
        const auto deg = v[5] + ((v[0] - 2) * v[5] * 2);
        const auto r1 = v[1];
        const auto c1 = v[2];
        const auto r2 = v[3];
        const auto c2 = v[4];
        delta_board[r1][c1] += deg;
        delta_board[r2 + 1][c2 + 1] += deg;
        delta_board[r2 + 1][c1] += -deg;
        delta_board[r1][c2 + 1] += -deg;
    }
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board.back().size(); ++j)
        {
            delta_board[i][j + 1] += delta_board[i][j];
        }
    }
    for (int j = 0; j < board.back().size(); ++j)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            delta_board[i + 1][j] += delta_board[i][j];
        }
    }
    for (int j = 0; j < board.back().size(); ++j)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            answer -= ((board[i][j] + delta_board[i][j]) <= 0);
        }
    }
    return answer;
}