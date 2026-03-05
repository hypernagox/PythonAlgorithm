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
void Solve()noexcept
{
    int n, m; cin >> n >> m;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        pq.emplace(x);
    }
    while (m--)
    {
        ll s = pq.top();
        pq.pop();
        s += pq.top();
        pq.pop();
        pq.emplace(s);
        pq.emplace(s);
    }
    ll res = 0;
    while (pq.size())
    {
        res += pq.top();
        pq.pop();
    }
    cout << res;
}
int main()
{
    FastIO();
    Solve();
}