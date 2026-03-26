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
pi arr[16];
int memo[16];
int GO(const int idx)
{
    if (idx > n + 1)return -INF;
    if (idx == n + 1)return 0;
    auto& ref = memo[idx];
    if (~ref)return ref;
    // 한다
    const int a = GO(idx + arr[idx].first) + arr[idx].second;
    // 안한다
    const int b = GO(idx + 1);
    return ref = max(a, b);
}
void Solve() noexcept
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    memset(memo, -1, sizeof(memo));
    cout << GO(1);
}
int main()
{
    FastIO();
    Solve();
}