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
int n;
int arr[1000002];
int memo[1000002];
int GO(const int x) noexcept
{
    if (x == 1)
    {
        return 1;
    }
    int& ret = memo[x];
    if (ret != -1)
    {
        return ret;
    }
    if (arr[x - 1] < arr[x])
    {
        ret = GO(x - 1) + 1;
    }
    else
    {
        ret = 1;
    }
    return ret;
}
void Solve() noexcept
{   
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x; cin >> x;
        arr[x] = i;
    }
    memset(memo, -1, sizeof(memo));
    int len = 0;
    for (int i = 1; i <= n; ++i)
    {
        len = max(len, GO(i));
    }
    cout << n - len;
}
int main()
{
    FastIO();
    Solve();
}