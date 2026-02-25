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
int n, m, J, S;
int dp[101][101];
void Solve()noexcept
{
    fill(&**dp, &**dp + 101 * 101, INF);
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
        dp[b][a] = min(dp[b][a], c);
    }
    cin >> J >> S;
    for (int i = 1; i <= n; ++i)dp[i][i] = 0;
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
    int ans = -1;
    int min_d = INF;
    int jdist = INF;
    for (int i = 1; i <= n; ++i)
    {
        if (J == i || S == i)continue;
        const auto dist = dp[J][i] + dp[S][i];
        if (min_d > dist)
        {
            min_d = dist;
        }
    }
    if (INF <= min_d)
    {
        cout << -1;
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (J == i || S == i)continue;
        if (dp[J][i] > dp[S][i])continue;
        const auto dist = dp[J][i] + dp[S][i];
        if (min_d == dist)
        {
            if (jdist > dp[J][i])
            {
                jdist = dp[J][i];
                ans = i;
            }
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}