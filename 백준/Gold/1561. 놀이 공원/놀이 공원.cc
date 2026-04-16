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
ll n, m;
ll arr[10001];
ll Cal(const ll mid)
{
    ll s = m;
    for (int i = 0; i < m; ++i)s += mid / arr[i];
    return s;
}
void Solve() noexcept
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)cin >> arr[i];
    if (n <= m)
    {
        cout << n;
        return;
    }
    ll left = 0;
    ll right = INT32_MAX * 31LL;
    ll ans = 0;
    while (left < right)
    {
        const auto mid = left + (right - left) / 2LL;
        const auto val = Cal(mid);
        if (n <= val)
        {
            ans = mid;
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    const auto before = Cal(ans - 1);
    auto nokori = n - before;
    for (int i = 0; i < m; ++i)
    {
        if (ans % arr[i] != 0)continue;
        if (--nokori == 0)
        {
            cout << i + 1;
            return;
        }
    }
}
int main()
{
    FastIO();
    Solve();
}