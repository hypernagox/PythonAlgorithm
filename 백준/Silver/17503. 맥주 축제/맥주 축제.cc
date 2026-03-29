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
ll n, m, k;
pll arr[200001];
bool Check(const ll mid)
{
    priority_queue<ll> pq;
    for (int i = 0; i < k; ++i)
    {
        const auto [level, prio] = arr[i];
        if (level > mid)break;
        pq.emplace(prio);
    }
    if (pq.size() < n)return false;
    ll s = 0;
    for (int i = 0; i < n; ++i)
    {
        s += pq.top();
        pq.pop();
    }
    return s >= m;
}
void Solve() noexcept
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr, arr + k);
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll total = 0;
    for (int i = 0; i < k; ++i)
    {
        const auto [level, prio] = arr[i];
        total += prio;
        pq.emplace(prio);
        if (pq.size() > n)
        {
            total -= pq.top();
            pq.pop();
        }
        if (pq.size() == n && total >= m)
        {
            cout << level;
            return;
        }
    }
    cout << -1;
}
int main()
{
    FastIO();
    Solve();
}