#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = 987654321;
constexpr const int MIN_INF = INF * -1;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int n, k;
int focus[1001];
int need[1001];
ll memo[1001][10001];
ll GO(const int idx, const int cur_time)
{
    if (cur_time < 0)return MIN_INF;
    if (-1 == idx)return 0;
    auto& ref = memo[idx][cur_time];
    if (~ref)return ref;
    // 선택한다.
    const auto a = GO(idx - 1, cur_time - need[idx]) + focus[idx];
    // 선택하지 않는다.
    const auto b = GO(idx - 1, cur_time);
    return ref = max(a, b);
}
void Solve()noexcept
{
    cin >> n >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> focus[i] >> need[i];
    }
    memset(memo, -1, sizeof(memo));
    cout << GO(k - 1, n);
}
int main()
{
    FastIO();
    Solve();
}
