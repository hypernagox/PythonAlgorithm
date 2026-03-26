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
    priority_queue<ll> pq1, pq2;
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        ll x; cin >> x;
        if (x <= 0)
        {
            pq1.emplace(-x);
        }
        else
        {
            pq2.emplace(x);
        }
    }
    ll res = 0;
    while (pq1.size())
    {
        const auto a = pq1.top();
        pq1.pop();
        if (pq1.size())
        {
            const auto b = pq1.top();
            pq1.pop();
            res += a * b;
        }
        else
        {
            res -= a;
        }
    }
    while (pq2.size())
    {
        const auto a = pq2.top();
        pq2.pop();
        if (pq2.size() && a != 1 && pq2.top() != 1)
        {
            const auto b = pq2.top();
            pq2.pop();
            res += a * b;
        }
        else
        {
            res += a;
        }
    }
    cout << res;
}
int main()
{
    FastIO();
    Solve();
}