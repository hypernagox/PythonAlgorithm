#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int n;
int id;
char b[1002][1002];
vector<vector<bool>> visited;
vector<set<int>> adj;
vector<int> cost;
vector<int> bestCost;
int g[1002][1002];
constexpr int dy[]{ -1,0,1,0 };
constexpr int dx[]{ 0,1,0,-1 };
constexpr int dy2[]{ -1, 0, 1, 0, -1, -1, 1, 1 };
constexpr int dx2[]{ 0, 1, 0, -1, -1, 1, 1, -1 };
void go(int y, int x)
{
    queue<pair<int, int>> q;
    q.emplace(y, x);
    g[y][x] = id;
    while (!q.empty()) {
        auto [curY, curX] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            const int ny = curY + dy[i];
            const int nx = curX + dx[i];
            if (ny < 0 || ny > n + 1 || nx < 0 || nx > n + 1) continue;
            if (b[ny][nx] != b[curY][curX]) continue;
            if (g[ny][nx]) continue;
            g[ny][nx] = id;
            q.emplace(ny, nx);
        }
    }
}

void go2(int y, int x) {
    queue<pair<int, int>> q;
    q.emplace(y, x);
    visited[y][x] = 1;
    while (!q.empty()) {
        const auto [curY, curX] = q.front();
        q.pop();
        ++cost[g[curY][curX]];
        for (int i = 0; i < 8; ++i) {
            const int ny = curY + dy2[i];
            const int nx = curX + dx2[i];
            if (ny < 0 || ny > n + 1 || nx < 0 || nx > n + 1) continue;
            if (g[ny][nx] == -1) continue;
            if (g[ny][nx] != g[curY][curX]) {
                adj[g[curY][curX]].emplace(g[ny][nx]);
            }
            else {
                if (visited[ny][nx]) continue;
                visited[ny][nx] = 1;
                q.emplace(ny, nx);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char c; cin >> c;
            b[i][j] = c;
        }
    }
    g[0][0] = -1;
    g[0][1] = -1;
    g[1][0] = -1;
    g[1][1] = -1;
    g[n][n] = -1;
    g[n][n + 1] = -1;
    g[n + 1][n] = -1;
    g[n + 1][n + 1] = -1;
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= n + 1; ++j) {
            if (g[i][j] == -1)continue;
            if (g[i][j])continue;
            ++id;
            go(i, j);
        }
    }
    visited.resize(n + 2, vector<bool>(n + 2));
    adj.resize(id + 1, {});
    cost.resize(id + 1);
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= n + 1; ++j) {
            if (g[i][j] == -1)continue;
            if (visited[i][j])continue;
            go2(i, j);
        }
    }
    cost[g[0][n + 1]] = 0;
    cost[g[n + 1][0]] = 0;
    bestCost.resize(id + 1, 1 << 30);
    priority_queue<pair<int, int>> pq;
    bestCost[g[0][n + 1]] = 0;
    pq.emplace(0, g[0][n + 1]);
    while (!pq.empty()) {
        const auto [v, n] = pq.top(); pq.pop();
        if (bestCost[n] < -v)continue;
        for (const auto next : adj[n]) {
            if (bestCost[next] > bestCost[n] + cost[next]) {
                bestCost[next] = bestCost[n] + cost[next];
                pq.emplace(-bestCost[next], next);
            }
        }
    }
    cout << bestCost[g[n + 1][0]];
}