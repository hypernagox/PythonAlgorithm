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
int costs[301];
int mat[301][301];
void Solve() noexcept
{
    int n; cin >> n;
    int min_cost = INF;
    int min_idx = 0;
    for (int i = 0; i < n; ++i) 
    {
        cin >> costs[i];
        if (min_cost > costs[i])
        {
            min_cost = costs[i];
            min_idx = i;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> mat[i][j];
        }
    }
    int ans = INF;
    for (int k = 0; k < n; ++k)
    {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.emplace(costs[k], k);
        bool visited[301]{};
        int s = 0;
        while (pq.size())
        {
            const auto [cost, cur] = pq.top();
            pq.pop();
            if (visited[cur])continue;
            visited[cur] = 1;
            s += cost;
           // cout << s << endl;
            for (int i = 0; i < n; ++i)
            {
                if (cur == i)continue;
                if (visited[i])continue;
                const auto new_cost = min(mat[cur][i], costs[i]);
                pq.emplace(new_cost, i);
            }
        }
        //cout << endl;
        ans = min(ans, s);
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}