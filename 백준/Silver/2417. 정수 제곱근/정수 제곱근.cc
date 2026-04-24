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
    ull n; cin >> n;
    ull low = 0;
    ull high = (ull)sqrt(UINT64_MAX);
    ull ans = 0;
    while (low < high)
    {
        const auto mid = low + (high - low) / 2ULL;
        const auto midq = mid * mid;
        if (midq >= n)
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