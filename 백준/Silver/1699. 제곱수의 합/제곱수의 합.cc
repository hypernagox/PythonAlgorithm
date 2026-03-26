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
int memo[100001];
int GO(const int cur)
{
    if (0 == cur)return 0;
    auto& ref = memo[cur];
    if (~ref)return ref;
    int res = INF;
    for (int i = (int)sqrt(cur); i >= 1; --i)
    {
        if (i * i <= cur)
        {
            res = min(res, GO(cur - i * i) + 1);
        }
    }
    return ref = res;
}
void Solve() noexcept
{
    cin >> n;
    memset(memo, -1, sizeof(memo));
    cout << GO(n);
}
int main()
{
    FastIO();
    Solve();
}