#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<const int>(1e9);
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
char board[1001][1001];
short memo[1001][1001];
int n, m;
short GO(const short y, const short x)noexcept
{
    if (y >= n || x >= m)return 0;
    auto& ref = memo[y][x];
    if (~ref)return ref;
    if (board[y][x] != '0')return ref = 0;
    const auto l = GO(y + 1, x);
    const auto r = GO(y, x + 1);
    const auto h = GO(y + 1, x + 1);
    return ref = 1 + min({ l,r,h });
}
void Solve()noexcept
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }
    memset(memo, -1, sizeof(memo));
    short ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            ans = max(ans, GO(i, j));
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}