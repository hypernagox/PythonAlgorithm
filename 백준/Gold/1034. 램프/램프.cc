#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
string board[51];
int z_count[51];
int n, m, k;
void Solve()noexcept
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> board[i];
        for (const auto z : board[i])
        {
            z_count[i] += (z == '0');
        }
    }
    cin >> k;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        const int z = z_count[i];
        if (!(z <= k && ((k & 1) == (z & 1)))) continue;
        int cnt = 1;
        for (int j = i + 1; j < n; ++j)
        {
            if (z_count[j] == z && board[j] == board[i]) ++cnt;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}
