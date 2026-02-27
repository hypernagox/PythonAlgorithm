#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<int>(1e9);
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int board[33][33];
int n;
ll memo[33][33][3];
bool CanGo(const int y, const int x)
{
    if (y < 0 || x < 0 || y >= n || x >= n)return false;
    if (board[y][x])return false;
    return true;
}
ll GO(const int cur_y, const int cur_x, const int cur_state)
{
    if (cur_y == n - 1 && cur_x == n - 1)return 1;
    const auto ny = cur_y + 1;
    const auto nx = cur_x + 1;
    auto& ref = memo[cur_y][cur_x][cur_state];
    if (~ref)return ref;
    ll res = 0;
    if (CanGo(cur_y, nx) && CanGo(ny, cur_x) && CanGo(ny, nx))
    {
        res += GO(ny, nx, 2); // 대각
    }
    if (0 == cur_state) // 가로
    {
        if (CanGo(cur_y, nx))
        {
            res += GO(cur_y, nx, 0); // 가로유지
        }
    }
    else if (1 == cur_state) // 세로
    {
        if (CanGo(ny, cur_x))
        {
            res += GO(ny, cur_x, 1); // 세로유지
        }
    }
    else // 대각
    {
        if (CanGo(cur_y, nx))
        {
            res += GO(cur_y, nx, 0);
        }
        if (CanGo(ny, cur_x))
        {
            res += GO(ny, cur_x, 1);
        }
    }
    return ref = res;
}
void Solve()noexcept
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }
    memset(memo, -1, sizeof(memo));
    cout << GO(0, 1, 0);
}
int main()
{
    FastIO();
    Solve();
}