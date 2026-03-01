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
int n;
int stats[21][21];
bool choice[21];
vector<int> teams[2];
int Cal(const int t)
{
    int s = 0;
    for (int i = 0; i < teams[t].size(); ++i)
    {
        const auto a = teams[t][i];
        for (int j = 0; j < teams[t].size(); ++j)
        {
            const auto b = teams[t][j];
            s += stats[a][b];
        }
    }
    return s;
}
int Cal()
{
    teams[0].clear();
    teams[1].clear();
    for (int i = 0; i < n; ++i)
    {
        teams[choice[i]].emplace_back(i);
    }
    return abs(Cal(0) - Cal(1));
}
int ans = INF;
void GO(const int cur, const int start)
{
    if (cur == n / 2)
    {
        ans = min(ans, Cal());
        return;
    }
    for (int i = start; i < n; ++i)
    {
        choice[i] = 1;
        GO(cur + 1, i + 1);
        choice[i] = 0;
    }
}
void Solve()noexcept
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> stats[i][j];
        }
    }
    GO(0, 0);
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}