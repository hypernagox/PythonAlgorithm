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
int visited[2002][2002];
void Solve() noexcept
{
    int s; cin >> s;
    queue<pi> q;
    visited[1][0] = 1;
    q.emplace(1,0);
    int ans = 0;
    while (q.size())
    {
        const auto [cur,clip] = q.front();
        q.pop();
        if (cur == s)
        {
            ans = visited[cur][clip] - 1;
            break;
        }
        // 불여넣기
        const auto v1 = cur + clip;
        if (v1 <= 2000)
        {
            if (!visited[v1][clip])
            {
                visited[v1][clip] = visited[cur][clip] + 1;
                q.emplace(v1,clip);
            }
        }
        // 하나 날리기
        const auto v2 = cur - 1;
        if (v2 >= 0)
        {
            if (!visited[v2][clip])
            {
                visited[v2][clip] = visited[cur][clip] + 1;
                q.emplace(v2,clip);
            }
        }
        if (!visited[cur][cur])
        {
            visited[cur][cur] = visited[cur][clip] + 1;
            q.emplace(cur, cur);
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}