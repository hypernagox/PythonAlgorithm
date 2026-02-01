#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll dp[21]{};
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	// dp[3] = 2;
	// dp[k] = (k - 1) * (dp[k-2] + dp[k-1]);
	for (int i = 3; i <= 20; ++i)
	{
		dp[i] = (i - 1) * (dp[i - 2] + dp[i - 1]);
	}
	int t; cin >> t;
	while (t--)
	{
		int k; cin >> k;
		cout << dp[k] << '\n';
	}
}