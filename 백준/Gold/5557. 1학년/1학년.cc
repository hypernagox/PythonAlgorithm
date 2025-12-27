#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int arr[101];
int n;
ll memo[101][21];
ll GO(const int idx, const ll cur_sum)
{
    if (idx == n - 1)
    {
        if (cur_sum == arr[idx])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    auto& ref = memo[idx][cur_sum];
    if (-1 != ref)return ref;
    ref = 0;
    ll a = 0;
    ll b = 0;
    // 더한다.
    if(cur_sum + arr[idx] <= 20)
        a += GO(idx + 1, cur_sum + arr[idx]) + 0;
    // 뺀다.
    if (cur_sum - arr[idx] >= 0)
        b += GO(idx + 1, cur_sum - arr[idx]) + 0;
    return ref = a + b;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    memset(memo, -1, sizeof(memo));
    cout << GO(1, arr[0]);
}