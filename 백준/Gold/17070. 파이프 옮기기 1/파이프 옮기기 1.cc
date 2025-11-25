#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int INF = 987654321;
// [y][x][상태]: 끝이 y,x이고 상태값일때 경우의 수
// [y][x][대각] = [y-1][x-1][세로] + [y-1][x-1][가로] + [y-1][x-1][대각]
// [y][x][가로] = [y][x-1][가로] + [y][x-1][대각]
// [y][x][세로] = [y-1][x][세로] + [y-1][x][대각]
int board[17][17];
int dp[17][17][3];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> board[i][j];
		}
	}
	dp[1][2][1] = 1;
	for (int y = 1; y <= n; ++y)
	{
		for (int x = 1; x <= n; ++x)
		{
			if (board[y][x])continue;
			if (board[y - 1][x] == 0 && board[y][x - 1] == 0)
			{
				dp[y][x][2] += dp[y - 1][x - 1][0] + dp[y - 1][x - 1][1] + dp[y - 1][x - 1][2];
			}
			dp[y][x][1] += dp[y][x - 1][1] + dp[y][x - 1][2];
			dp[y][x][0] += dp[y - 1][x][0] + dp[y - 1][x][2];
		}
	}
	const int res = dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
	cout << res;
}