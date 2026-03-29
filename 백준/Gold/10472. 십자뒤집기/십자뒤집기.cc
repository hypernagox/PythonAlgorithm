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
vector<string> board;
vector<string> target;
bool visited[3][3];
constexpr const int dy[]{ -1,0,1,0 };
constexpr const int dx[]{ 0,1,0,-1 };
void Fill(const int y,const int x)
{
    for (int i = 0; i < 4; ++i)
    {
        const auto ny = y + dy[i];
        const auto nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= 3 || nx >= 3)continue;
        if (board[ny][nx] == '.')board[ny][nx] = '*';
        else board[ny][nx] = '.';
    }
    if (board[y][x] == '.')board[y][x] = '*';
    else board[y][x] = '.';
}
int ans = INF;
int GO(const int cnt = 0)
{
    if (cnt >= ans)return INF;
    if (target == board)
    {
        return cnt;
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (visited[i][j])continue;
            visited[i][j] = 1;
            Fill(i, j);
            ans = min(ans, GO(cnt + 1));
            Fill(i, j);
            visited[i][j] = 0;
        }
    }
    return ans;
}
void Solve() noexcept
{   
    int t; cin >> t;
    target.resize(3);
    for (int i = 0; i < 3; ++i)target[i].resize(3);
    board.resize(3);
    for (int i = 0; i < 3; ++i)board[i].resize(3);
    while (t--)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                board[i][j] = '.';
                cin >> target[i][j];
            }
        }
        cout << GO() << '\n';
        ans = INF;
    }
}
int main()
{
    FastIO();
    Solve();
}