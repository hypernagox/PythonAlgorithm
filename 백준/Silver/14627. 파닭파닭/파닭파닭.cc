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
bool Check(const vector<ull>& v, const ull mid, const ull val)
{
    ull s = 0;
    for (const auto i : v)
    {
        s += (i / mid);
    }
    return s >= val;
}
void Solve() noexcept
{
    int n, m; cin >> n >> m;
    vector<ull> v; v.reserve(n);
    while (n--)
    {
        ull x; cin >> x;
        v.emplace_back(x);
    }
    ull l = 1;
    ull r = INT64_MAX;
    ull ans = 1;
    while (l < r)
    {
        const auto mid = (l + r) / 2LL;
        if (Check(v, mid, m))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    cout << accumulate(v.begin(), v.end(), 0ULL) - ans * (ull)m;
}
int main()
{
    FastIO();
    Solve();
}