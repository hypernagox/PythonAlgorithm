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
int visited[1000001];
void Solve() noexcept
{
    int F, S, G, U, D; cin >> F >> S >> G >> U >> D;
    queue<int> q;
    q.emplace(S);
    visited[S] = 1;
    while (q.size())
    {
        const auto cur = q.front();
        q.pop();
        if (cur == G)
        {
            cout << visited[cur] - 1;
            return;
        }
        const auto v1 = cur + U;
        if (v1 <= F)
        {
            if (visited[v1] == 0)
            {
                visited[v1] = visited[cur] + 1;
                q.emplace(v1);
            }
        }
        const auto v2 = cur - D;
        if (v2 >= 1)
        {
            if (visited[v2] == 0)
            {
                visited[v2] = visited[cur] + 1;
                q.emplace(v2);
            }
        }
    }
    cout << "use the stairs";
}
int main()
{
    FastIO();
    Solve();
}