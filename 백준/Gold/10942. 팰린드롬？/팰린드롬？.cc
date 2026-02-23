#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<const int>(1e9);
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int arr[2001];
int dp[2001][2001]; 
int n, m;
void Solve() noexcept
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    // len = 1
    for (int i = 0; i < n; ++i) dp[i][i] = 1;

    // len = 2
    for (int i = 0; i + 1 < n; ++i)
    {
        if (arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
    }

    // len >= 3
    for (int len = 3; len <= n; ++len)
    {
        for (int l = 0; l + len - 1 < n; ++l)
        {
            int r = l + len - 1;
            if (arr[l] == arr[r] && dp[l + 1][r - 1]) dp[l][r] = 1;
        }
    }

    cin >> m;
    while (m--)
    {
        int l, r; cin >> l >> r;
        cout << dp[l - 1][r - 1] << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}