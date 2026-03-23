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
pi arr[1001];
int n;
int memo[1001][1001];
// dp[idx][day] -> idx번째 고려하고 지금 날짜가 day일때의 답
// dp[idx][day] -> dp[idx+1][day] vs dp[idx+1][day+1] 다음 idx고려했을때 내가이걸 했을때랑 안했을때 중 더큰거
int GO(const int idx, const int cur_day)
{
    if (idx == n)return 0;
    auto& ref = memo[idx][cur_day];
    if (~ref)return ref;
    int a = 0;
    int b = 0;
    if (cur_day <= arr[idx].first)
    {
        a = GO(idx + 1, cur_day + 1) + arr[idx].second; // 과제를함
    }
    b = GO(idx + 1, cur_day); // 과제를 안함
    return ref = max(a, b);
}
void Solve() noexcept
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n);
    memset(memo, -1, sizeof(memo));
    cout << GO(0, 1);
}
int main()
{
    FastIO();
    Solve();
}