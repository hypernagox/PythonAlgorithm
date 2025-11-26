#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
char board[51][51];
int dp[51][51];
bool visited[51][51];
int n, m;
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
bool flag = false;
int GO(const int y, const int x)
{
	if (y < 0 || x < 0 || y >= n || x >= m || 'H' == board[y][x])return 0;
	auto& ref = dp[y][x];
	if (visited[y][x])
	{
		flag = true;
		return -1;
	}
	if (ref)return ref;
	const int delta = board[y][x] - '0';
	visited[y][x] = true;
	for (int i = 0; i < 4; ++i)
	{
		const int ny = y + dy[i] * delta;
		const int nx = x + dx[i] * delta;
		ref = max(ref,GO(ny, nx) + 1);
	}
	visited[y][x] = false;
	return ref;
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
	const auto res = GO(0, 0);
	if (!flag)cout << res;
	else cout << -1;
}