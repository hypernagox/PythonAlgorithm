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
int n;
int arr[5001];
ll k;
ll memo[5001];
ll GO(const int idx)
{
    if (idx == n - 1)return 0;
    auto& ref = memo[idx];
    if (~ref)return ref;
    ll res = INF;
    for (ll i = idx + 1; i < n; ++i)
    {
        const auto power = (i - idx) * (1LL + abs(arr[i] - arr[idx]));
        res = min(res, max(power, GO(i)));
    }
    return ref = res;
}
void Solve() noexcept
{
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    memset(memo, -1, sizeof(memo));
    cout << GO(0);
}
int main()
{
    FastIO();
    Solve();
}