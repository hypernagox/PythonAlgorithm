#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<int>(1e9) + 1;
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int board[1001][1001];
int n, m;
int memo[1001][1001];
int GO(const int y, const int x)
{
    if (y >= n || x >= m)return 0;
    auto& ref = memo[y][x];
    if (~ref)return ref;
    return ref = max({ GO(y + 1, x),
        GO(y, x + 1),
        GO(y + 1, x + 1) }) + board[y][x];
}
void Solve() noexcept
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
    cout << GO(0, 0);
}
int main()
{
    FastIO();
    Solve();
}