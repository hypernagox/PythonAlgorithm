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
void Solve()noexcept
{
    int n; cin >> n;
    int ans = 0;
    vector<string> v; v.reserve(n);
    char msg[21];
    while (n--)
    {
        cin >> msg;
        if ("ENTER" == string_view{ msg })
        {
            ranges::sort(v);
            const auto [b, e] = ranges::unique(v);
            ans += b - v.begin();
            v.clear();
        }
        else
        {
            v.emplace_back(move(msg));
        }
    }
    ranges::sort(v);
    const auto [b, e] = ranges::unique(v);
    ans += b - v.begin();
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}