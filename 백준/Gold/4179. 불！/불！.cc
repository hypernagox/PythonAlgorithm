#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <cstring>
using namespace std;
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
int r, c;
struct Block
{
	char type;
	int time = 1 << 20;
};
Block maze[1001][1001];
bool RangeCheck(const int y, const int x)
{
	return !(y < 0 || x < 0 || y >= r || x >= c);
}
bool visited[1001][1001];
struct Data
{
	int y;
	int x;
	int cost = 0;
	int time = 0;
};
void SpreadFire()
{
	queue<Data> q;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if ('F' == maze[i][j].type)
			{
				q.emplace(i, j, 0, 0);
			}
		}
	}
	while (!q.empty())
	{
		const auto [y, x, cost, time] = q.front();
		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			const auto ny = y + dy[k];
			const auto nx = x + dx[k];
			if (!RangeCheck(ny, nx))
			{
				continue;
			}
			if (visited[ny][nx])continue;
			visited[ny][nx] = true;
			if ('#' != maze[ny][nx].type)
			{
				maze[ny][nx].type = 'F';
				maze[ny][nx].time = min(maze[ny][nx].time, maze[y][x].time + 1);
				q.emplace(ny, nx, 0, time + 1);
			}
		}
	}
}
int bfs(const int y, const int x)
{
	queue<Data> q;
	q.emplace(y, x, 0, 0);
	visited[y][x] = 1;
	while (!q.empty())
	{
		const auto [y, x, cost, time] = q.front();
		q.pop();
		const auto next_time = min(time + 1, 1000);
		for (int k = 0; k < 4; ++k)
		{
			bool flag = false;
			const auto ny = y + dy[k];
			const auto nx = x + dx[k];
			if (!RangeCheck(ny, nx))
			{
				return cost + 1;
			}
			if (visited[ny][nx])
			{
				continue;
			}
			if ('#' == maze[ny][nx].type)
			{
				continue;
			}
			if (next_time >= maze[ny][nx].time)
			{
				continue;
			}
			visited[ny][nx] = true;
			q.emplace(ny, nx, cost + 1, next_time);
		}
	}
	return -1;
}
int GO(const int y, const int x)
{
	SpreadFire();
	memset(visited, 0, sizeof(visited));
	return bfs(y, x);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c;
	int y, x;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> maze[i][j].type;
			if ('J' == maze[i][j].type)
			{
				y = i;
				x = j;
			}
			if ('F' == maze[i][j].type)
			{
				maze[i][j].time = 0;
			}
		}
	}
	const auto ans = GO(y, x);
	if (-1 == ans)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		cout << ans;
	}
}