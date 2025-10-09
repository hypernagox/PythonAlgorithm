#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int dp[1025][1025];
int table[1025][1025];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> table[i][j];
		}
	}
	// dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + table[i][j] - dp[i - 1][j - 1];
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + table[i][j] - dp[i - 1][j - 1];
		}
	}
	while (m--)
	{
		int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;

		ll res = dp[r2][c2];
		res -= dp[r2][c1 - 1];
		res -= dp[r1 - 1][c2];
		res += dp[r1 - 1][c1 - 1];
		cout << res << '\n';
	}
}