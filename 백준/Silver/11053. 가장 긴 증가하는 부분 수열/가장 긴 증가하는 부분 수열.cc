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
int arr[1001];
int n;
int memo[1001];
int GO(const int last_idx)
{
    auto& ref = memo[last_idx];
    if (~ref)return ref;
    int res = 0;
    for (int i = 0; i < last_idx; ++i)
    {
        if (arr[i] < arr[last_idx])
        {
            res = max(res, GO(i));
        }
    }
    return ref = res + 1;
}
void Solve() noexcept
{
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    memset(memo, -1, sizeof(memo));
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, GO(i));
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}