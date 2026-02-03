#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
int h, w;
char board[31][31];
bool visited[31][31];
int ans = 987654321;
int empty_cnt = 0;
bool CanGo(int y, int x) 
{
    if (y < 0 || x < 0 || y >= h || x >= w) return false;
    if (board[y][x] == '*') return false;
    if (visited[y][x]) return false;
    return true;
}
void DFS(int y, int x, int cnt, int v_cnt) 
{
    if (cnt >= ans) return;
    if (v_cnt == empty_cnt)
    {
        ans = min(ans, cnt);
        return;
    }
    for (int k = 0; k < 4; ++k) 
    {
        int ny = y;
        int nx = x;
        vector<pair<int, int>> trace;
       for(;;)
        {
            const int ty = ny + dy[k];
            const int tx = nx + dx[k];
            if (!CanGo(ty, tx)) break;
            ny = ty;
            nx = tx;
            visited[ny][nx] = true;
            trace.push_back({ ny, nx });
        }
        if (trace.empty()) continue;
        DFS(ny, nx, cnt + 1, v_cnt + trace.size());
        for (auto p : trace)
        {
            visited[p.first][p.second] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int case_num = 1;
    while (cin >> h >> w) 
    {
        ans = 987654321;
        empty_cnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < h; ++i) 
        {
            for (int j = 0; j < w; ++j) 
            {
                cin >> board[i][j];
                if (board[i][j] == '.') empty_cnt++;
            }
        }
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j) 
            {
                if (board[i][j] == '.') 
                {
                    visited[i][j] = true;
                    DFS(i, j, 0, 1);
                    visited[i][j] = false;
                }
            }
        }
        if (ans == 987654321) cout << "Case " << case_num++ << ": " << -1 << '\n';
        else cout << "Case " << case_num++ << ": " << ans << '\n';
    }
}