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
int memo[1001][1001];
int GO(const int i,const int s)
{
    if (i >= n)return (s == k) ? 1 : 0;
    auto& ref = memo[i][s];
    if (-1 != ref)return ref;
    // 고른다 -> 골랐으니 + 2번인덱스부터 시작
    const auto a = GO(i + 2, s + 1);
    // 고르지 않는다 -> 다음 인덱스 고려
    const auto b = GO(i + 1, s);
    return ref = (a + b) % MOD;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    memset(memo, -1, sizeof(memo));
    // 0번을 고르지않고  1번부터 쭉 + 0번고르고, 1번재끼고 마지막꺼 못고르니 n-3개에서의 경우의수
    cout << (GO(1, 0) + GO(3, 1)) % MOD;
}