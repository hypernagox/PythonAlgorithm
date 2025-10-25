#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int mat[102][102];
int visited[102][102];
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) 
{
	for (const auto& v : rectangle)
	{
		const auto lbx = v[0]* 2;
		const auto lby = v[1]* 2;
		const auto rtx = v[2]* 2;
		const auto rty = v[3]* 2;
		for (int i = lby; i <= rty; ++i)
		{
			for (int j = lbx; j <= rtx; ++j)
			{
				mat[i][j] = 1;
			}
		}
	}
	for (const auto& v : rectangle)
	{
		const auto lbx = (v[0] * 2) + 1;
		const auto lby = (v[1] * 2) + 1;
		const auto rtx = (v[2] * 2) - 1;
		const auto rty = (v[3] * 2) - 1;
		for (int i = lby; i <= rty; ++i)
		{
			for (int j = lbx; j <= rtx; ++j)
			{
				mat[i][j] = 0;
			}
		}
	}
	characterX *= 2;
	characterY *= 2;
	itemX *= 2;
	itemY *= 2;
	queue<pi> q;
	q.emplace(characterY, characterX);
	visited[characterY][characterX] = 1;
	constexpr const int dy[]{ -1,0,1,0 };
	constexpr const int dx[]{ 0,1,0,-1 };
	while (!q.empty())
	{
		const auto [y, x] = q.front();
		q.pop();
		if (y == itemY && x == itemX)break;
		for (int i = 0; i < 4; ++i)
		{
			const auto ny = y + dy[i];
			const auto nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= 101 || nx >= 101)continue;
			if (0 == mat[ny][nx])continue;
			if (visited[ny][nx])continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.emplace(ny, nx);
		}
	}
	return (visited[itemY][itemX] - 1) / 2;
}