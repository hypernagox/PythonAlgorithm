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
ll arr[51];
int n;
ll memo[51];
int GO(const int idx)
{
    if (n == idx)return 0;
    auto& ref = memo[idx];
    if (~ref)return ref;
    int a = -INF;
    // 묶기
    if (idx + 1 < n)
    {
        a = GO(idx + 2) + (arr[idx] * arr[idx + 1]);
    }
    // 안묶기
    const int b = GO(idx + 1) + arr[idx];
    return ref = max(a, b);
}
void Solve() noexcept
{
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    sort(arr, arr + n);
    memset(memo, -1, sizeof(memo));
    cout << GO(0);
}
int main()
{
    FastIO();
    Solve();
}