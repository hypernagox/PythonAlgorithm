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
void Solve()noexcept
{
    map<int, int> space;
    map<int, int> space_info;
    map<int, int> car_info;
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int x; cin >> x;
        space.emplace(i, x);
    }
    for (int i = 1; i <= m; ++i)
    {
        int x; cin >> x;
        car_info.emplace(i, x);
    }
    queue<int> q;
    int ans = 0;
    map<int, int> uses;
    space_info = space;
    for (int i = 0; i < m * 2; ++i)
    {
        int x; cin >> x;
        const auto num = abs(x);
        if (x > 0)
        {
            q.emplace(x);
        }
        else
        {
            const auto target = uses.find(num);
            const auto [car_num, space_num] = *target;
            space.emplace(space_num, space_info[space_num]);
            uses.erase(target);
        }
        if (!space.empty() && !q.empty())
        {
            ans += space.begin()->second * car_info[q.front()];
            uses.emplace(q.front(), space.begin()->first);
            space.erase(space.begin());
            q.pop();
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}