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
    ll n, m; cin >> n >> m;
    vector<ll> v; v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        v.emplace_back(x);
    }
    ll s = 0;
    priority_queue<ll> pq;
    ll ans = 0;
    for (const auto i : v)
    {
        pq.emplace(i);
        s += i;
        while (pq.size() && s >= m)
        {
            s -= pq.top() * 2LL;
            //s = max(s, 0LL);
            pq.pop();
            ++ans;
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}