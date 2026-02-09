#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
constexpr const pi dirs[]
{
    {-1,-2},
    {-2,-1},
    {-2,1},
    {-1,2},
    {1,2},
    {2,1},
    {2,-1},
    {1,-2}
};
int n;
bool CanGo(const int y, const int x)
{
    if (y < 0 || x < 0 || y >= n || x >= n)return false;
    return true;
}
int visited[301][301];
int BFS(const pi start, const pi end)
{
    queue<pi> q;
    q.emplace(start);
    memset(visited, 0, sizeof(visited));
    visited[start.first][start.second] = 1;
    while (!q.empty())
    {
        const auto [y, x] = q.front();
        if (end == q.front())
        {
            break;
        }
        q.pop();
        for (int i = 0; i < 8; ++i)
        {
            const auto ny = y + dirs[i].first;
            const auto nx = x + dirs[i].second;
            if (!CanGo(ny, nx))continue;
            if (visited[ny][nx])continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.emplace(ny, nx);
        }
    }
    return visited[end.first][end.second] - 1;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        pi start, end;
        cin >> start.first >> start.second >> end.first >> end.second;
        cout << BFS(start, end) << '\n';
    }
}