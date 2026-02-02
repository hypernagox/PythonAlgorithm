#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int dp[201][201];
int arr[201];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, k; cin >> n >> m;
	fill(&dp[0][0], &dp[0][0] + (201 * 201), 987654321);
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dp[a][b] = min(dp[a][b], c);
	}
	for (int i = 1; i <= n; ++i)
	{
		dp[i][i] = 0;
	}
	cin >> k;
	for (int i = 0; i < k; ++i)cin >> arr[i];
	for (int t = 1; t <= n; ++t)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				dp[i][j] = min(dp[i][j], dp[i][t] + dp[t][j]);
			}
		}
	}
	int res = 987654321;
	// 각 도시들에 대해서
	
	for (int i = 1; i <= n; ++i)
	{
		int s = 0;
		for (int j = 0; j < k; ++j)
		{
			// 집 ->i 까지 / i - > 집까지
			s = max(s, dp[arr[j]][i] + dp[i][arr[j]]);
		}
		res = min(res, s);
	}
	//cout << res;
	vector<int> ans;
	for (int i = 1; i <= n; ++i)
	{
		int s = 0;
		for (int j = 0; j < k; ++j)
		{
			// 집 ->i 까지 / i - > 집까지
			s = max(s, dp[arr[j]][i] + dp[i][arr[j]]);
		}
		if (s == res)ans.emplace_back(i);
	}
	for (const auto i : ans)cout << i << ' ';
}