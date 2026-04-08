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
queue<int> q[101];
void Solve() noexcept
{
    int n, m; cin >> n >> m;
    int arr[100];
    for (int i = 0; i < m; ++i)
    {
        int x; cin >> x;
        arr[i] = x;
        q[x].emplace(i);
    }
    for (int i = 1; i <= m; ++i)
    {
        q[i].emplace(INF);
    }
    int cnt = 0;
    set<pi> s;
    set<int> cur;
    for (int i = 0; i < m; ++i)
    {
        const auto val = arr[i];
        q[val].pop();
        const auto next = q[val].front();
        if (cur.count(val))
        {
            s.erase(s.begin());
            s.emplace(next, val);
        }
        else
        {
            if (s.size() >= n)
            {
                const auto [idx, val] = *--s.end();
                cur.erase(val);
                s.erase(--s.end());
                ++cnt;
            }
            s.emplace(next, val);
            cur.emplace(val);       
        }
    }
    cout << cnt;
}
int main()
{
    FastIO();
    Solve();
}