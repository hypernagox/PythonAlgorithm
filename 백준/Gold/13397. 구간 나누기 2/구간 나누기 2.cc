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
bool Check(int arr[], const int mid, const int n, const int m)
{
    int s = 1;
    int cur_min = arr[0];
    int cur_max = arr[0];
    for (int i = 0; i < n; ++i)
    {
        cur_max = max(cur_max, arr[i]);
        cur_min = min(cur_min, arr[i]);
        if (cur_max - cur_min > mid)
        {
            ++s;
            cur_min = arr[i];
            cur_max = arr[i];
        }
    }
    return s <= m;
}
void Solve() noexcept
{
    int arr[5000];
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    int low = 0;
    int high = INT32_MAX / 2;
    int ans = 0;
    while (low < high)
    {
        const auto mid = low + (high - low) / 2;
        if (Check(arr, mid, n, m))
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