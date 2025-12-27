#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int a, b, c, d;
struct Data
{
    pi ab;
    int cost = 0;
    const auto operator<(const Data& d)const noexcept {
        return ab < d.ab;
    }
};
queue<Data> q;
set<pi> visited;
void GO(const int cur_a, const int cur_b,const int cost)
{
    if (visited.emplace(cur_a, cur_b).second)
    {
        q.emplace(make_pair( cur_a, cur_b ), cost + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c >> d;
    q.emplace(make_pair(0, 0), 0);
    while (!q.empty())
    {
        const auto [cur_a, cur_b] = q.front().ab;
        const auto cost = q.front().cost;
        q.pop();
        if (cur_a == c && cur_b == d)
        {
            cout << cost;
            // 끝
            return 0;
        }
        // 가득채우기 A
        if (cur_a < a)
        {
            GO(a, cur_b, cost);
        }
        // 가득채우기 B
        if (cur_b < b)
        {
            GO(cur_a, b, cost);
        }
        // 다버리기 A
        if (cur_a > 0)
        {
            GO(0, cur_b, cost);
        }
        // 다버리기 B
        if (cur_b > 0)
        {
            GO(cur_a, 0, cost);
        }
        const auto cap_a = a - cur_a; // a의 여유공간 
        const auto cap_b = b - cur_b; // b의 여유공간 
        // a->b 
        GO(max(0, cur_a - cap_b), min(b, cur_b + cur_a), cost);
        // b->a 
        GO(min(a, cur_a + cur_b), max(0, cur_b - cap_a), cost);
    }
    cout << -1;
}