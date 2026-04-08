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
constexpr const int MOD = 1000000;
int n;
int memo[101][101][2];
int GO(const int len, const int rank, const int dir)
{
    if (rank < 1 || rank > len) return 0;
    if (len == 2)
    {
        if (dir == 1 && rank == 2) return 1;
        if (dir == 0 && rank == 1) return 1;
        return 0;
    }
    int& ref = memo[len][rank][dir];
    if (ref != -1) return ref;
    ref = 0;
    if (dir == 1)
    {
        for (int prevRank = 1; prevRank <= rank - 1; ++prevRank)
        {
            ref += GO(len - 1, prevRank, 0);
            ref %= MOD;
        }
    }
    else
    {
        for (int prevRank = rank; prevRank <= len - 1; ++prevRank)
        {
            ref += GO(len - 1, prevRank, 1);
            ref %= MOD;
        }
    }
    return ref;
}
void Solve() noexcept
{
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return;
    }
    memset(memo, -1, sizeof(memo));
    int res = 0;
    for (int rank = 1; rank <= n; ++rank)
    {
        res += GO(n, rank, 0);
        res %= MOD;
        res += GO(n, rank, 1);
        res %= MOD;
    }
    cout << res % MOD;
}
int main()
{
    FastIO();
    Solve();
}