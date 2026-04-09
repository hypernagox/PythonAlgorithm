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
int n, k;
int arr[50001];
int memo[50001][3];
int acc[50001];
int GO(const int idx, const int car)
{
    if (idx >= n)return 0;
    if (car == 3)return 0;
    auto& ref = memo[idx][car];
    if (~ref)return ref;
    // 버림
    // 여기서부터 다해봄
    const int last = min(idx + k - 1, n - 1);
    const auto val = acc[last] - acc[idx] + arr[idx];
    return ref = max(GO(idx + 1, car), GO(last + 1, car + 1) + val);
}
void Solve() noexcept
{
    cin >> n;
    int acc_val = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        acc_val += arr[i];
        acc[i] = acc_val;
    }
    cin >> k;
    memset(memo, -1, sizeof(memo));
    cout << GO(0, 0);
}
int main()
{
    FastIO();
    Solve();
}