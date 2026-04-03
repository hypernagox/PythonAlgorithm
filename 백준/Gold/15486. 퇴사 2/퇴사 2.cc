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
pi arr[1500001];
int n;
int memo[1500001];
int GO(const int cur_day)
{
    if (cur_day > n + 1)return -INF;
    if (cur_day == n + 1)return 0;
    auto& ref = memo[cur_day];
    if (~ref)return ref;
    // 한다.
    const int a = GO(cur_day + arr[cur_day].first) + arr[cur_day].second;
    // 안한다.
    const int b = GO(cur_day + 1);
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