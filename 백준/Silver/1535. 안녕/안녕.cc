#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
int n;
int cost[101];
int happy[101];
int memo[101][101];
int GO(const int cur_hp = 100, const int idx = 0)
{
    if (idx == n)return 0;
    auto& ref = memo[cur_hp][idx];
    if (ref)return ref;
    int a = 0;
    if (cur_hp - cost[idx] > 0)
    {
        // 인사할수있으면 해봄
        a = GO(cur_hp - cost[idx], idx + 1) + happy[idx];
    }
    // 하지 않는다
    const int b = GO(cur_hp, idx + 1);
    return ref = max(a, b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> cost[i];
    for (int i = 0; i < n; ++i)cin >> happy[i];
    cout << GO();
}