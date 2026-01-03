#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
constexpr const int MOD = 1000000003;
int n, k;
int memo[1001][1001][2];
int GO(const int i,const int sum,const bool selected)
{
    if (i == n)return (sum == k) ? 1 : 0;
    auto& ref = memo[i][sum][selected];
    if (-1 != ref)return ref;
    int res = 0;
    // 이전에 선택하지않았으면 선택해볼수있다.
    if (!selected)
    {
        res += GO(i + 1, sum + 1, true);
        res %= MOD;
    }
    res += GO(i + 1, sum, false);//선택하지않고 넘어간다.
    res %= MOD;
    return ref = res;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    memset(memo, -1, sizeof(memo));
    // 0번을 고르지않고 쭉 + 0번고르고, 1번재끼고 마지막꺼 못고르니 n-3개에서의 경우의수
    cout << (GO(0, 0, true) + GO(3, 1, false)) % MOD;
}