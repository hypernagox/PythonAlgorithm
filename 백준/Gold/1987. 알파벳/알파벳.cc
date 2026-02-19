#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
constexpr const int DIRS = sizeof(dy) / sizeof(dy[0]);
char board[21][21];
int r, c;
unordered_map<ll, int> memo;
ll MakeKey(const int y, const int x, const int state)
{
    return (ll)(state) << 32 | y << 8 | x;
}
int GO(const int y, const int x, const int state)
{
    const auto key = MakeKey(y, x, state);
    const auto iter = memo.find(key);
    if (memo.end() != iter)return iter->second;
    int res = 1;
    for (int i = 0; i < DIRS; ++i)
    {
        const auto ny = y + dy[i];
        const auto nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= r || nx >= c)
        {
            continue;
        }
        const auto next_alpha= board[ny][nx] - 'A';
        if (state & (1 << next_alpha))
        {
            continue;
        }
        res = max(res, GO(ny, nx, state | (1 << next_alpha)) + 1);
    }
    memo.emplace(key, res);
    return res;
}
void Solve()noexcept
{
    cin >> r >> c;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> board[i][j];
        }
    }
    memo.reserve(r * c * 26);
    cout << GO(0, 0, 1 << (board[0][0] - 'A'));
}
int main()
{
    FastIO();
    Solve();
}