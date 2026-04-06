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
ull arr[100001];
ull n, m;
bool Check(const ull mid)
{
    ull cnt = 1;
    ull s = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > mid)return false;
        if (s + arr[i] > mid)
        {
            s = 0;
            ++cnt;
            if (cnt > m)return false;
        }
        s += arr[i];
    }
    return cnt <= m;
}
void Solve() noexcept
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    ull low = 1;
    ull high = INT32_MAX / 2;
    ull ans = 1;
    while (low < high)
    {
        const auto mid = low + (high - low) / 2ULL;
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