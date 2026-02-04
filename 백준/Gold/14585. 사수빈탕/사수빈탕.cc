#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
constexpr const int dy[]{ 1,0 };
constexpr const int dx[]{ 0,1 };
set<pi> s;
int memo[301][301];
int GO(const int y, const int x)
{
    const auto times = y + x;
    if (times == m)return 0;
    auto& ref = memo[y][x];
    if (~ref)return ref;
    int res = 0;
    for (int i = 0; i < 2; ++i)
    {
        const auto ny = y + dy[i];
        const auto nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= 300 || nx >= 300)continue;
        res = max(res,GO(ny, nx));
    }
    return ref = res + max(0,(((int)s.count({y,x}) * m) - times));
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int a, b; cin >> a >> b;
        s.emplace(b, a);
    }
    memset(memo, -1, sizeof(memo));
    cout << GO(0, 0);
}