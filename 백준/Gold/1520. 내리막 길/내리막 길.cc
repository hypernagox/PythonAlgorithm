#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int INF = 987654321;
int n, m;
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
int board[501][501];
int memo[501][501];
int GO(const int y, const int x)
{
	if (y == n - 1 && x == m - 1)
	{
		return 1;
	}
	auto& ref = memo[y][x];
	if (-1 != ref)return ref;
	int res = 0;
	const auto cur = board[y][x];
	for (int i = 0; i < 4; ++i)
	{
		const auto ny = y + dy[i];
		const auto nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
		const auto next = board[ny][nx];
		if (cur > next)
		{
			res += GO(ny, nx);
		}
	}
	return ref = res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}
	memset(memo, -1, sizeof(memo));
	cout << GO(0, 0);
}