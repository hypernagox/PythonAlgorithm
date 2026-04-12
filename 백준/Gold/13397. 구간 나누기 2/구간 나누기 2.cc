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
short n, m;
short arr[5000];
bool Check(const short mid)
{
    short cur_min = arr[0];
    short cur_max = arr[0];
    short cnt = 1;
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
    short low = 0;
    short high = 10002;
    short ans = low;
    while (low < high)
    {
        const auto mid = low + (high - low) / 2;
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