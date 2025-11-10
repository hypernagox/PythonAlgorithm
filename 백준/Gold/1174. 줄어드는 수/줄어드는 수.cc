#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
vector<string> dp[11][11];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	// dp[i][j] -> i자리수인데 맨앞이 j인 녀석들
	// i는 자리수
	for (int i = 0; i < 10; ++i)
	{
		dp[1][i].emplace_back(to_string(i));
	}
	for (int i = 2; i <= 10; ++i)
	{
		// 맨 앞자리가 j일 때
		for (int j = i - 1; j <= 9; ++j)
		{
			// i - 1 자리수인데 맨앞이 k인녀석들
			for (int k = 0; k <= j - 1; ++k)
			{
				for (const auto& num : dp[i - 1][k])
				{
					dp[i][j].emplace_back(to_string(j) + num);
				}
			}
		}
	}
	int cnt = 1;
	for (const auto& i : dp)
	{
		for (const auto& j : i)
		{
			for (const auto& k : j)
			{
				if (cnt++ == n)
				{
					cout << k;
					return 0;
				}
			}
		}
	}
	cout << -1;
}