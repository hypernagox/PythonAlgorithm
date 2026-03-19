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
bool Check(const vector<ll>& v, const ll mid, const ll m)
{
    ll s = 0;
    // mid 시간에 스태프 i가 만들수있는  풍선수
    for (const auto i : v)
    {
        s += (mid / i);
    }
    return s >= m;
}
void Solve() noexcept
{
    int n, m; cin >> n >> m;
    vector<ll> v; v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        v.emplace_back(x);
    }
    ll l = 1;
    ll r = INT64_MAX /8 ;
    ll ans = 0;
    while (l < r)
    {
        const auto mid = (l + r) / 2ll;
        if (Check(v, mid, m))
        {
            ans = mid; // 늘 마지막으로 조건이 성립할 때를 기억
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}