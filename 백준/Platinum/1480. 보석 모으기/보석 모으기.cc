#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int n, m, c;
int items[15];
int memo[15][15][1<<14];
int GO(const int bag_idx, const int cur_cap, const int get_jewel)
{
    if (bag_idx == m)
    {
        return 0;
    }
    auto& ref = memo[bag_idx][cur_cap][get_jewel];
    if (ref)return ref;
    int a = 0;
    for (int i = 0; i < n; ++i)
    {
        // 일단 이 보석이 주워졌나?
        const bool is_get = (get_jewel) & (1 << i);
        // 지금가방에서 용량이되나이거?
        const auto next_cap = cur_cap - items[i];
        const bool can_get = next_cap >= 0;
        if (!is_get && can_get)
        {
            // 지금가방을 그대로 쓴다.
            a = max(a, GO(bag_idx, next_cap, get_jewel | (1 << i)) + 1);
        }
    }
    // 지금 가방은 쓰지않고 킵해두고 다음가방을 써본다.
    const int b = GO(bag_idx + 1, c, get_jewel);
    return ref = max(a, b);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> c;
    for (int i = 0; i < n; ++i)
    {
        cin >> items[i];
    }
    cout << GO(0, c, 0);
}