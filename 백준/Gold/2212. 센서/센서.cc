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
    vector<int> v1, v2;
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        v1.emplace_back(x);
    }
    sort(v1.begin(), v1.end());
    for (int i = 0; i < n - 1; ++i)
    {
        v2.emplace_back(v1[i + 1] - v1[i]);
    }
    sort(v2.begin(), v2.end());
    int ans = 0;
    for (int i = 0; i < (int)v2.size() - (k - 1); ++i)
    {
        ans += v2[i];
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}