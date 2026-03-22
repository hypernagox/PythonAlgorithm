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
int dp[1001][1001];
pi dosi[1001];
bool sdosi[1001];
int t;
int specialDist[1001];
int GetDist(const int i, const int j)
{
    int val = INF;
    if (sdosi[i] && sdosi[j])val = t;
    const auto i_dosi = dosi[i];
    const auto j_dosi = dosi[j];
    return min(val, abs(i_dosi.first - j_dosi.first) + abs(i_dosi.second - j_dosi.second));
}
void Solve() noexcept
{
    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), INF);
    int n; cin >> n >> t;
    for (int i = 1; i <= n; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        sdosi[i] = a;
        dosi[i] = { b,c };
    }
    for (int i = 1; i <= n; ++i)
    {
        specialDist[i] = INF;
        if (sdosi[i])
        {
            specialDist[i] = 0;
            continue;
        }
        for (int j = 1; j <= n; ++j)
        {
            if (!sdosi[j]) continue;
            specialDist[i] = min(specialDist[i], GetDist(i, j));
        }
    }
    int m;
    cin >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        const int direct = GetDist(a, b);
        const int teleport = specialDist[a] + t + specialDist[b];
        cout << min(direct, teleport) << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}