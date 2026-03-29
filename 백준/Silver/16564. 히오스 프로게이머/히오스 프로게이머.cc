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
bool Check(const vector<ll>& v, const ll mid, const ll val)
{
    ll s = 0;
    for (const auto i : v)
    {
        s += max(0LL, mid - i);
    }
    return s <= val;
}
void Solve() noexcept
{   
    ll n, k; cin >> n >> k;
    vector<ll> v; v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        ll x; cin >> x;
        v.emplace_back(x);
    }
    ll left = 1;
    ll right = INT32_MAX;
    ll ans = left;
    while (left < right)
    {
        const auto mid = left + (right - left) / 2LL;
        if (Check(v, mid, k))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}