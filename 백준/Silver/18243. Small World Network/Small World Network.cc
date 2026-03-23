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
int dp[101][101];
void Solve() noexcept
{
    int n, m; cin >> n >> m;
    while (m--)
    {
        int a, b; cin >> a >> b;
        dp[a][b] = dp[b][a] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (dp[i][j] == 0)dp[i][j] = INF;
            }
        }
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dp[i][j] > 6)
            {
                cout << "Big World!";
                return;
           }
        }
    }
    cout << "Small World!";
}
int main()
{
    FastIO();
    Solve();
}