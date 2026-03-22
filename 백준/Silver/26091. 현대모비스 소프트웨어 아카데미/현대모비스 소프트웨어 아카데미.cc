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
int arr[100001];
void Solve() noexcept
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int ans = 0;
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        const auto val = arr[l] + arr[r];
        if (val >= m)
        {
            ++l;
            --r;
            ++ans;
        }
        else
        {
            ++l;
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}