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
int k, n, m;
int arr1[2002];
int arr2[2002];
ll memo1[2000002];
ll memo2[2000002];
void Solve() noexcept
{
    cin >> k >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> arr2[i];
    }
    for (int start = 0; start < n; ++start)
    {
        int s = 0;
        for (int len = 0; len < n - 1; ++len)
        {
            s += arr1[(start + len) % n];
            ++memo1[s];
        }
    }
    int total1 = 0;
    for (int i = 0; i < n; ++i)
    {
        total1 += arr1[i];
    }
    ++memo1[total1];
    for (int start = 0; start < m; ++start)
    {
        int s = 0;
        for (int len = 0; len < m - 1; ++len)
        {
            s += arr2[(start + len) % m];
            ++memo2[s];
        }
    }
    int total2 = 0;
    for (int i = 0; i < m; ++i)
    {
        total2 += arr2[i];
    }
    ++memo2[total2];
    ll ans = 0;
    for (int i = 1; i <= k - 1; ++i)
    {
        ans += memo1[i] * memo2[k - i];
    }
    cout << ans + memo1[k] + memo2[k];
}
int main()
{
    FastIO();
    Solve();
}