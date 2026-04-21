#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
int coins[101];
int n, k;
int dp[10001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)cin >> coins[i];
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        const auto cur = coins[i];
        for (int s = cur; s <= k; ++s)
        {
            dp[s] += dp[s - cur];
        }
    }
    cout << dp[k];
}