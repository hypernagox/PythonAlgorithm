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
int memo[1002][1002];
int GO(const int prev_idx, const int cur_idx)
{
    if (cur_idx == n)return 0;
    auto& ref = memo[prev_idx + 1][cur_idx];
    if (~ref)return ref;
    int a = 0;
    if (prev_idx == -1 || arr[prev_idx] < arr[cur_idx])
    {
        a = GO(cur_idx, cur_idx + 1) + 1;
    }
    return ref = max(a, GO(prev_idx, cur_idx + 1));
}
void Solve() noexcept
{
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    memset(memo, -1, sizeof(memo));
    cout << GO(-1, 0);
}
int main()
{
    FastIO();
    Solve();
}