#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int dp[3][100001];
int table[100001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)cin >> table[i];
	// dp[0][i] = i는 먹지않았다
	// dp[1][i] = i를먹긴했는데 이전에먹고먹은거다 -> dp[2][i-1] + table[i]/2
	// dp[2][i] = i를먹었는데 처음먹은거다 -> dp[0][i-1] + table[i]
	dp[1][1] = table[1];
	dp[2][1] = table[1];
	for (int i = 2; i <= n; ++i)
	{
		dp[1][i] = dp[2][i - 1] + table[i] / 2;
		dp[2][i] = dp[0][i - 1] + table[i];
		dp[0][i] = max({ dp[0][i - 1], dp[1][i - 1], dp[2][i - 1] });
	}
	cout << max({ dp[0][n], dp[1][n], dp[2][n] });
}