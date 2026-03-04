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
int n, t;
int need_time[101];
int score[101];
int memo[101][10001];
int GO(const int idx, const int nokori)
{
    if (0 > nokori)
    {
        return -INF;
    }
    if (idx == n)
    {
        return 0;
    }
    auto& ref = memo[idx][nokori];
    if (~ref)return ref;
    return ref = max(GO(idx + 1, nokori - need_time[idx]) + score[idx],
        GO(idx + 1, nokori));
}
void Solve()noexcept
{
    cin >> n >> t;
    for (int i = 0; i < n; ++i)cin >> need_time[i] >> score[i];
    memset(memo, -1, sizeof(memo));
    cout << GO(0, t);
}
int main()
{
    FastIO();
    Solve();
}