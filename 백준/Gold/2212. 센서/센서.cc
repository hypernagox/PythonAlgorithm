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
    int n, k; cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        v.emplace_back(x);
    }
    sort(v.begin(), v.end());
    vector<int> diff;
    for (int i = 0; i < n - 1; ++i)
    {
        diff.emplace_back(v[i + 1] - v[i]);
    }
    sort(diff.begin(), diff.end());
    int ans = 0;
    for (int i = 0; i < (int)diff.size() - (k - 1); ++i)
    {
        ans += diff[i];
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}