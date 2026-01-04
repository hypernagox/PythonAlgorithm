#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int D[21][21];
int n;
int memo[21][(1 << 21)];
int GO(const int human, const int job)
{
    if (human == n)return 0;
    auto& ref = memo[human][job];
    if (-1 != ref)return ref;
    int res = INF;
    for (int i = 0; i < n; ++i)
    {
        // 이 사람이 i번 째 일을 해본다
        if (job & (1 << i))continue;
        res = min(res, GO(human + 1, job | (1 << i)) + D[human][i]);
    }
    return ref = res;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> D[i][j];
        }
    }
    memset(memo, -1, sizeof(memo));
    cout << GO(0, 0);
}