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
    ull n;
    cin >> n;
    ull cur = 1;
    for (ull i = 1; i <= n; ++i)
    {
        cur *= i;
        while (cur % 10ULL == 0ULL)
        {
            cur /= 10ULL;
        }
        cur %= 1000000000000ULL;
    }
    auto ans = to_string(cur);
    while (!ans.empty() && ans.back() == '0')ans.pop_back();
    cout << ans.substr(ans.size() - 5);
}
int main()
{
    FastIO();
    Solve();
}