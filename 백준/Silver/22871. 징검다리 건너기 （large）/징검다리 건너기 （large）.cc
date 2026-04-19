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
int memo[5001];
bool GO(const int idx)
{
    if (idx == n)return 1;
    if (idx == n - 1)return 1;
    auto& ref = memo[idx];
    if (~ref)return ref;
    for (ll i = idx + 1; i < n; ++i)
    {
        const auto power = (i - idx) * (1LL + abs(arr[i] - arr[idx]));
        if (power <= k && GO(i))
        {
            return ref = true;
        }
    }
    return ref = false;
}
void Solve() noexcept
{
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    ll low = 0;
    ll high = INT32_MAX;
    ll ans = 0;
    while(low < high)
    {
        const auto mid = (low + high) / 2LL;
        k = mid;
        memset(memo, -1, sizeof(memo));
        if (GO(0))
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