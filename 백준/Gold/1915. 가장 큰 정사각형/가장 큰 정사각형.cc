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
char board[1001][1001];
int memo[1001][1001];
int n, m;
int GO(const int y,const int x)
{
    if (y == 0 && x == 0)return 0;
    if (y <= 0 || x <= 0)return 0;
    auto& ref = memo[y][x];
    if (board[y][x] == '0')return ref = 0;
    if (~ref)return ref;
    const int a = GO(y - 1, x);
    const int b = GO(y, x - 1);
    const int c = GO(y - 1, x - 1);
    return ref = min({ a,b,c }) + 1;
}
void Solve() noexcept
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> board[i][j];
        }
    }
    memset(memo, -1, sizeof(memo));
    memo[0][0] = 0;
    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            ans = max(ans, GO(i, j));
        }
    }
    cout << ans * ans;
}
int main()
{
    FastIO();
    Solve();
}