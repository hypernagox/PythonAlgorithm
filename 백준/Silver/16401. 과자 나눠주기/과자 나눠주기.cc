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
int m, n;
int arr[1000001];
bool Check(const int mid)
{
    int s = 0;
    for (int i = 0; i < n; ++i)
    {
        s += (arr[i] / mid);
        if (s >= m)return true;
    }
    return false;
}
void Solve()noexcept
{
    cin >> m >> n;
    int l = 1;
    int r = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        r = max(r, arr[i]);
    }
    ++r;
    while (l < r)
    {
        const auto mid = (l + r) / 2;
        if (Check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}