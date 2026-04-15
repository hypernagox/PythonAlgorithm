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
    int t; cin >> t;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    while (t--)
    {
        int n; cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int x; cin >> x;
            pq.emplace(x);
        }
        ll s = 0;
        while (pq.size())
        {
            const auto v1 = pq.top();
            pq.pop();
            if (pq.empty())break;
            const auto v2 = pq.top();
            pq.pop();
            const auto v3 = v1 + v2;
            s += v3;
            pq.emplace(v3);
        }
        cout << s << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}