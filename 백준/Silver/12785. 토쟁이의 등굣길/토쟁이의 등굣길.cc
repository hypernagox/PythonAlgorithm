#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int dp[300][300];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int w, h; cin >> w >> h;
	int tx, ty; cin >> tx >> ty;
	for (int i = 1; i <= h; ++i)
	{
		dp[i][1] = 1;
	}
	for (int i = 1; i <= w; ++i)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= h; ++i)
	{
		for (int j = 2; j <= w; ++j)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000007;
		}
	}
	const auto toast_root = dp[ty][tx];
	for (int i = ty; i <= h; ++i)
	{
		dp[i][tx] = toast_root;
	}
	for (int i = tx; i <= w; ++i)
	{
		dp[ty][i] = toast_root;
	}
	for (int i = ty + 1; i <= h; ++i)
	{
		for (int j = tx + 1; j <= w; ++j)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000007;
		}
	}
	cout << dp[h][w];
}