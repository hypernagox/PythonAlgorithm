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
void Solve()noexcept
{
    int n; cin >> n;
    int arr[100];
    for (int i = 0; i < n; ++i)cin >> arr[i];
    int delta = 0;
    int ans = 0;
    for (int i = n - 1; i >= 1; --i)
    {
        const auto high = arr[i] - delta;
        const auto low = arr[i - 1];
        if (high <= low)
        {
            delta = (low - high) + 1;
            ans += delta;
        }
        else
        {
            delta = 0;
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}