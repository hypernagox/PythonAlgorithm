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
void Solve() noexcept
{
    int n, m; cin >> n >> m;
    priority_queue<int> pq[2];
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        pq[x < 0].emplace(abs(x));
    }
    pq[0].emplace(0);
    pq[1].emplace(0);
    ll res = 0;
    int max_v = max(pq[0].top(), pq[1].top());
    for (int i = 0; i < 2; ++i)
    {
        while (pq[i].size())
        {
            res += pq[i].top() * 2;
            pq[i].pop();
            for (int j = 0; j < m - 1 && pq[i].size(); ++j)
            {
                pq[i].pop();
            }
        }
    }
    cout << res - max_v;
}
int main()
{
    FastIO();
    Solve();
}