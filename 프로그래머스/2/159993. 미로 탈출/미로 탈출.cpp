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
int visited[101][101];
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
void BFS(const pair<int, int> start,const vector<string>& maps)
{
	queue<pair<int, int>> q;
	q.emplace(start);
	while (!q.empty())
	{
		const auto [y, x] = q.front();
		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			const auto ny = y + dy[k];
			const auto nx = x + dx[k];
			if (ny < 0 || nx < 0 || ny >= maps.size() || nx >= maps.back().size())
			{
				continue;
			}
			if (visited[ny][nx])
			{
				continue;
			}
			if ('X' == maps[ny][nx])
			{
				continue;
			}
			visited[ny][nx] = visited[y][x] + 1;
			q.emplace(ny, nx);
		}
	}
}
int solution(vector<string> maps)
{
	int answer = 0;
	pair<int, int> start;
	pair<int, int> l;
	pair<int, int> end;
	for (int i = 0; i < maps.size(); ++i)
	{
		for (int j = 0; j < maps.back().size(); ++j)
		{
			if ('L' == maps[i][j])
			{
				l = make_pair(i, j);
			}
			else if ('S' == maps[i][j])
			{
				start = make_pair(i, j);
			}
			else if ('E' == maps[i][j])
			{
				end = make_pair(i, j);
			}
		}
	}
	BFS(start, maps);
	answer += visited[l.first][l.second];
	if (answer == 0)
	{
		return -1;
	}
	memset(visited, 0, sizeof(visited));
	BFS(l, maps);
	const auto val = visited[end.first][end.second];;
	answer += visited[end.first][end.second];
	if (val == 0)
	{
		return -1;
	}
	return answer;
}