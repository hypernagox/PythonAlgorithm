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
int acc[100001];
void Solve() noexcept
{
    int n; cin >> n;
    vector<int> v; v.reserve(n);
    int s = 0;
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        s += v.emplace_back(x);
        acc[i] = s;
    }
    int ans = 0;
    // 벌 - 벌 - 꿀
    for (int i = 1; i < n - 1; ++i)
    {
        const auto val = (acc[n - 1] - acc[0] - v[i]) + (acc[n - 1] - acc[i]);
        ans = max(ans, val);
    }
    // 꿀 - 벌 - 벌
    for (int i = 1; i < n - 1; ++i)
    {
        const auto val = (acc[n - 2] - v[i]) + acc[i] - v[i];
        ans = max(ans, val);
    }
    // 벌 - 꿀 - 벌
    for (int i = 1; i < n - 1; ++i)
    {
        const auto val = acc[n - 1] - acc[i] + v[i] - v[0] - v[n - 1] + acc[i];
        ans = max(ans, val);
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}