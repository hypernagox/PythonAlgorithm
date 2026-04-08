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
ll arr[100001];
ll n, m;
bool Check(const ll mid)
{
    ll s = 0;
    ll cnt = 1;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > mid)return false;
        s += arr[i];
        if (s > mid)
        {
            s = arr[i];
            ++cnt;
        }
    }
    return cnt <= m;
}
void Solve() noexcept
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    ll low = 1;
    ll high = INT32_MAX + 1LL;
    ll ans = 1;
    while (low < high)
    {
        const auto mid = low + (high - low) / 2LL;
        if (Check(mid))
        {
            ans = mid;
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}