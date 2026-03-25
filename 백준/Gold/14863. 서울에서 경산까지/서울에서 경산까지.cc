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
pi items[2][101];
int n, k;
ll memo[101][100001];
ll GO(const int idx,const int cur_time)
{
    if (cur_time < 0)return -INF;
    if (idx == n)return 0;
    auto& ref = memo[idx][cur_time];
    if (~ref)return ref;
    ll res = -INF;
    for (int i = 0; i < 2; ++i)
    {
        res = max(res, GO(idx + 1, cur_time - items[i][idx].first) + items[i][idx].second);
    }
    return ref = res;
}
void Solve() noexcept
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cin >> items[j][i].first >> items[j][i].second;
        }
    }
    memset(memo, -1, sizeof(memo));
    cout << GO(0, k);
}
int main()
{
    FastIO();
    Solve();
}