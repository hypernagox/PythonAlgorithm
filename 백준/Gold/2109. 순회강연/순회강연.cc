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
        int pay, day; cin >> pay >> day;
        v.emplace_back(day, pay);
    }
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    ll s = 0;
    for (const auto [day, pay] : v)
    {
        s += pay;
        pq.emplace(pay);
        if (pq.size() > day)
        {
            s -= pq.top();
            pq.pop();
        }
    }
    cout << s;
}
int main()
{
    FastIO();
    Solve();
}