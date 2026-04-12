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
    int n; cin >> n;
    vector<pi> v; v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        v.emplace_back(b, c);
    }
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.emplace(-1);
    for (const auto [start_time, end_time] : v)
    {
        if (pq.top() <= start_time)
        {
            pq.pop();
        }
        pq.emplace(end_time);
    }
    cout << pq.size();
}
int main()
{
    FastIO();
    Solve();
}