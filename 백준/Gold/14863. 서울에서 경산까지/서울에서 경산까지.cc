#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
struct Data
{
    ll cost;
    ll value;
};
Data walk[101];
Data ride[101];
int n, k;
ll memo[101][100001];
int ans = 0;
ll GO(const int idx,const int time)
{
    if (idx == n)
    {
        return 0;
    }
    auto& ref = memo[idx][time];
    if (-1 != ref)return ref;
    ref = 0;
    ll a = 0;
    ll b = 0;
    // 걷기선택
    if (time - walk[idx].cost >= 0)
    {
        a = GO(idx + 1, time - walk[idx].cost) + walk[idx].value;
    }
    // 자전거선택
    if (time - ride[idx].cost >= 0)
    {
        b = GO(idx + 1, time - ride[idx].cost) + ride[idx].value;
    }
    if (a + b == 0)return ref = -INF;
    return ref = max(a, b);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < n; ++i)
    {
        cin >> walk[i].cost >> walk[i].value >> ride[i].cost >> ride[i].value;
    }
    cout << GO(0, k);
}