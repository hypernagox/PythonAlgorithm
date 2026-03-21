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
constexpr const int stones[]{ 1,3,4 };
int memo[1001];
int GO(const int cur)
{
    auto& ref = memo[cur];
    if (~ref)return ref;
    int flag = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (cur - stones[i] == 0)return 1; // 승리
        if (cur - stones[i] > 0)
        {
            flag |= !GO(cur - stones[i]);
        }
    }
    return ref = flag;
}
void Solve() noexcept
{
    constexpr const char ans[][3]{ "SK","CY" };
    memset(memo, -1, sizeof(memo));
    int n; cin >> n;
    cout << ans[!GO(n)];
}
int main()
{
    FastIO();
    Solve();
}