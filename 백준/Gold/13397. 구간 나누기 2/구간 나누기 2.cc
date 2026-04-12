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
int n, m;
int arr[5001];
bool Check(const ll mid)
{
    int cur_min = arr[0];
    int cur_max = arr[0];
    int cnt = 1;
    for (int i = 0; i < n; ++i)
    {
        cur_min = min(cur_min, arr[i]);
        cur_max = max(cur_max, arr[i]);
        if (cur_max - cur_min > mid)
        {
            ++cnt;
            if (cnt > m)return false;
            cur_min = cur_max = arr[i];
        }
    }
    return true;
}
void Solve() noexcept
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    ll low = 0;
    ll high = 10002;
    ll ans = low;
    while (low < high)
    {
        const auto mid = low + (high - low) / 2LL;
        if (Check(mid))
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