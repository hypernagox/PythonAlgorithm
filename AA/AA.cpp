#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
#include <map>
using namespace std;
int dp[101][1001];
pair<int, int> p[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> p[i].first >> p[i].second;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (p[i].second <= j)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - p[i].second] + p[i].first);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][m];
}