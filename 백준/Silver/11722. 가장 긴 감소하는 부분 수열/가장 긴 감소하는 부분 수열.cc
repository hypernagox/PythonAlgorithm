#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int n;
int arr[1001];
int memo[1001];
int GO(const int idx)
{
    if (idx == n)return 0;
    auto& ref = memo[idx];
    if (~ref)return ref;
    int res = 1;
    for (int i = idx + 1; i < n; ++i)
    {
        if (arr[idx] > arr[i])
        {
            res = max(res, GO(i) + 1);
        }
    }
    return ref = res;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    memset(memo, -1, sizeof(memo));
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        res = max(res, GO(i));
    }
    cout << res;
}