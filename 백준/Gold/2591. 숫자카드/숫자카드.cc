#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<const int>(1e9);
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
string str;
int memo[41];
int GO(int idx)
{
    if (idx == str.size()) return 1;
    if (str[idx] == '0') return 0;
    auto& ref = memo[idx];
    if (~ref) return ref;
    int res = 0;
    res += GO(idx + 1);
    if (idx + 1 < str.size())
    {
        int val = (str[idx] - '0') * 10 + (str[idx + 1] - '0');
        if (val <= 34)
        {
            res += GO(idx + 2);
        }
    }
    return ref = res;
}
void Solve() noexcept
{
    cin >> str;
    memset(memo, -1, sizeof(memo));
    cout << GO(0);
}
int main()
{
    FastIO();
    Solve();
}