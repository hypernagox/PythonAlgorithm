#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int n, k;
ll memo[1001][1001][2];
ll lim;
int GO(const int i,const ll num,const bool prev)
{
   // if (num == k)return 1;
    if (i == lim)
    {
        return (num == k) ? 1 : 0;
    }
    auto& ref = memo[i][num][prev];
    if (-1 != ref)return ref;
    ll v = 0;
    // 이전에안했으면
    if (!prev)
    {
        // 칠할수있음
        v = GO(i + 1, num + 1, true);
        v %= 1000000003;
    }
    // 칠하지않는다
    v += GO(i + 1, num, false);
    v %= 1000000003;
    return ref = v % 1000000003;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    memset(memo, -1, sizeof(memo));
    // 1번선택
    lim = n - 1;
    const auto a = GO(2, 1, 0);
    lim = n;
    memset(memo, -1, sizeof(memo));
    // 1번 미선택
    const auto b = GO(1, 0, 0);
    cout << (a + b) % 1000000003;
}