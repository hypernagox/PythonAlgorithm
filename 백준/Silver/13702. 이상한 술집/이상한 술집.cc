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
ll arr[10001];
int n, k;
ll Check(const ll mid)
{
    ll s = 0;
    for (int i = 0; i < n; ++i)
    {
        s += arr[i] / mid;
    }
    return s;
}
void Solve() noexcept
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    ll l = 1;
    ll r = INT32_MAX;
    ll ans = l;
    while (l < r)
    {
        const auto mid = (l + r) / 2LL;
        const auto capacity = Check(mid);
        if (capacity >= k)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}