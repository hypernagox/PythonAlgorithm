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
int n, m;
int chu[31];
int memo[31][15001 * 2];
int GO(const int idx, const int cur)
{
    if (cur > 15000)return false;
    if (0 == cur)return true;
    if (idx == n)return 0 == cur;
    auto& ref = memo[idx][cur + 15000];
    if (~ref)return ref;
    int res = 0;
    res |= GO(idx + 1, cur + chu[idx]); // 물건쪽
    res |= GO(idx + 1, cur - chu[idx]); // 물건 반대쪽
    res |= GO(idx + 1, cur); // 이 추를 포기함
    return ref = res;
}
void Solve()noexcept
{
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> chu[i];
    cin >> m;
    memset(memo, -1, sizeof(memo));
    constexpr const char ans[]{ 'N','Y' };
    while (m--)
    {
        int x; cin >> x;
        cout << ans[GO(0, x)] << ' ';
    }
}
int main()
{
    FastIO();
    Solve();
}