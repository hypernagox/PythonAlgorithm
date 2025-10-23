#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int table[11][100001];
int dp[11][100001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// dp[디저트][i] = dp[같은거][i-1] + 값/2 vs max(dp[다른거들][i-1]...) + 값 
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> table[i][j];
		}
	}
	for (int j = 0; j < m; ++j)
	{
		dp[j][0] = table[j][0];
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			// 지금 j번째 디저트 먹을건데
			for (int k = 0; k < m; ++k)
			{
				// 전날에 k번째 먹었을경우
				if (j == k)
				{
					dp[j][i] = max(dp[j][i], dp[k][i - 1] + table[j][i] / 2);
				}
				else
				{
					dp[j][i] = max(dp[j][i], dp[k][i - 1] + table[j][i]);
				}
			}
		}
	}
	int max_val = 0;
	for (int i = 0; i < m; ++i)
	{
		max_val = max(max_val, dp[i][n - 1]);
	}
	cout << max_val;
}