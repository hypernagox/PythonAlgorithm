#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
bool visited[100001];
int parents[100001];
vector<int> v;
int bfs(const int s, const int e)
{
    queue<pi> q;
    q.emplace(s, 0);
    parents[s] = -1;
    visited[s] = true;
    while (!q.empty())
    {
        const auto [cur,cost] = q.front();
        q.pop();
        if (cur == e)
        {
            int child = cur;
            for (;;)
            {
                v.emplace_back(child);
                child = parents[child];
                if (child == -1)break;
            }
            reverse(v.begin(), v.end());
            return cost;
        }
        if (cur < e && !visited[cur + 1])
        {
            visited[cur + 1] = true;
            parents[cur + 1] = cur;
            q.emplace(cur + 1, cost + 1);
        }
        if (cur > 0 && !visited[cur - 1])
        {
            visited[cur - 1] = true;
            parents[cur - 1] = cur;
            q.emplace(cur - 1, cost + 1);
        }
        if (cur * 2 <= 100000 && !visited[cur * 2])
        {
            visited[cur * 2] = true;
            parents[cur * 2] = cur;
            q.emplace(cur * 2, cost + 1);
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int s, e; cin >> s >> e;
    cout << bfs(s, e) << '\n';
    for (const auto i : v)cout << i << ' ';
}