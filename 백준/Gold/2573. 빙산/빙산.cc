#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<int>(1e9) + 1;
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
int n, m;
int mat[301][301];
bool visited[301][301];
void GO(const int y, const int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; ++i)
    {
        const auto ny = y + dy[i];
        const auto nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
        if (mat[ny][nx] <= 0)continue;
        if (visited[ny][nx])continue;
        GO(ny, nx);
    }
}
struct Data
{
    int y, x, val;
};
vector<Data> v;
void Melt()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (mat[i][j] == 0)continue;
            int cnt = 0;
            for (int k = 0; k < 4; ++k)
            {
                const auto ny = i + dy[k];
                const auto nx = j + dx[k];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
                if (mat[ny][nx] > 0)continue;
                ++cnt;
            }
            if (cnt)
            {
                v.emplace_back(i, j, cnt);
            }
        }
    }
    for (const auto [y, x, val] : v)
    {
        mat[y][x] = max(0, mat[y][x] - val);
    }
    v.clear();
}
void Solve() noexcept
{
    cin >> n >> m;
    v.reserve(n * m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> mat[i][j];
        }
    }
    for (int k = 1; k <= 400; ++k)
    {
        Melt();
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (visited[i][j])continue;
                if (mat[i][j] <= 0)continue;
                GO(i, j);
                ++cnt;
            }
        }
        if (cnt >= 2)
        {
            cout << k;
            return;
        }
        memset(visited, 0, sizeof(visited));
    }
    cout << 0;
}
int main()
{
    FastIO();
    Solve();
}