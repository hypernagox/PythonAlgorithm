#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int mat[1001][1001];
int r, c;
int dp[1002][1002];
int left_dir[1002];
int right_dir[1002];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> mat[i][j];
			dp[i][j] = mat[i][j];
		}
	}
	for (int i = 1; i < r; ++i)
	{
		dp[i][0] += dp[i - 1][0];
	}
	for (int i = 1; i < c; ++i)
	{
		dp[0][i] += dp[0][i - 1];
	}
	for (int i = 1; i < r; ++i)
	{
		left_dir[0] = dp[i - 1][0] + mat[i][0];
		right_dir[c - 1] = dp[i - 1][c - 1] + mat[i][c - 1];
		for (int j = 1; j < c; ++j)
		{
			const int L = j;
			const int R = c - 1 - j;
			left_dir[L] = max(dp[i - 1][L], left_dir[L - 1]) + mat[i][L];
			right_dir[R] = max(dp[i - 1][R], right_dir[R + 1]) + mat[i][R];
		}
		for (int j = 0; j < c; ++j)
		{
			dp[i][j] = max(left_dir[j], right_dir[j]);
		}
	}
	cout << dp[r - 1][c - 1];
}