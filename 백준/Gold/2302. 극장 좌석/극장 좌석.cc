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
bool visited[41];
int n;
int memo[41];
int GO(const int cur_num)
{
    if (cur_num >= n)
    {
        return 1;
    }
    auto& ref = memo[cur_num];
    if (~ref)return ref;
    int res = 0;
    // 제자리에 앉는다.
    res += GO(cur_num + 1);
    // 오른쪽에 앉는다. -> 옆사람과 swap 자동결정
    if (!visited[cur_num] && !visited[cur_num + 1])
    {
        res += GO(cur_num + 2);
    }
    return ref = res;
}
void Solve() noexcept
{
    int m;
    cin >> n >> m;
    while (m--)
    {
        int x; cin >> x;
        visited[x] = 1;
    }
    memset(memo, -1, sizeof(memo));
    cout << GO(1);
}
int main()
{
    FastIO();
    Solve();
}