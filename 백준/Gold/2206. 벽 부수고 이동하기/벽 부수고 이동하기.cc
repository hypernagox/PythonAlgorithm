#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
int n, m;
char maze[1001][1001];
int visited[2][1001][1001];
queue<pair<bool,pi>> q;
bool CanGo(const int y, const int x)
{
	return !(y < 0 || x < 0 || y >= n || x >= m);
}
void bfs(const pi start, const pi end)
{
	q.emplace(make_pair(false, start));
	while (!q.empty())
	{
		const bool break_wall = q.front().first;
		const auto [y, x] = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			bool now_break = false;
			const auto ny = y + dy[k];
			const auto nx = x + dx[k];
			if (!CanGo(ny,nx))
			{
				continue;
			}
			if ('1' == maze[ny][nx])
			{
				if (break_wall)
				{
					continue;
				}
				else
				{
					now_break = true;
				}
			}
			if (visited[break_wall][ny][nx])
			{
				continue;
			}
			visited[now_break || break_wall][ny][nx] = visited[break_wall][y][x] + 1;
			q.emplace(now_break || break_wall, make_pair(ny, nx));
		}
	}
}
int sol()
{
	const pi s{ 0,0 };
	const pi end{ n - 1,m - 1 };
	visited[0][0][0] = 1;
	visited[1][0][0] = 1;
	bfs(s, end);
	int res = 1 << 20;
	for (int i = 0; i < 2; ++i)
	{
		const auto dist = visited[i][end.first][end.second];
		if (0 == dist)
		{
			continue;
		}
		res = min(res, dist);
	}
	return 1 << 20 == res ? -1 : res;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> maze[i][j];
		}
	}
	cout << sol();
}