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
ll GCD(const ll a, const ll b)
{
    return 0 == b ? a : GCD(b, a % b);
}
void Solve()noexcept
{
    ll a, b, c, d; cin >> a >> b >> c >> d;
    const auto a1 = GCD(a, b);
    const auto a2 = GCD(c, d);
    a /= a1;
    b /= a1;
    c /= a2;
    d /= a2;
    const auto a3 = (b * d) / GCD(b, d);
    const auto a4 = a * a3 / b;
    const auto a5 = c * a3 / d;
    const auto a6 = GCD(a4 + a5, a3);
    cout << (a4 + a5) / a6 << ' ' << a3 / a6;
}
int main()
{
    FastIO();
    Solve();
}