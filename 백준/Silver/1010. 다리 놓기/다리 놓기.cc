#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int n, m;
long long memo[31][31];
long long GO(const int idx, const int selected)
{
    if (idx == n)
    {
        return 1;
    }
    auto& ref = memo[idx][selected];
    if (~ref)return ref;
    long long ret = 0;
    for (int i = selected + 1; i <= m; ++i)
    {
        ret += GO(idx + 1, i);
    }
    return ref = ret;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        memset(memo, -1, sizeof(memo));
        cin >> n >> m;
        cout << GO(0, 0) << '\n';
    }
}