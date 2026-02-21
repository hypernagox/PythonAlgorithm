#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = 987654321;
constexpr const int MIN_INF = INF * -1;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
bool IsPrime[3000001];
int visited[3000001];
int n, a, b;
void Init()
{
    fill(begin(IsPrime), end(IsPrime), true);
    IsPrime[0] = IsPrime[1] = 0;
    for (int i = 2; i <= (3000000); ++i)
    {
        if (!IsPrime[i])continue;
        for (int j = i + i; j <= 3000000; j += i)
        {
            IsPrime[j] = 0;
        }
    }
}
void Solve() noexcept
{
    Init();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        queue<pi> q;
        q.emplace(0, n);

        ll ans = INF;
       
        fill(visited, visited + 3000001, INF);
        visited[n] = 0;

        while (!q.empty())
        {
            const auto [cost, cur] = q.front();
            q.pop();

        
            if (visited[cur] < cost) continue;

            if (IsPrime[cur] && cur >= a && cur <= b)
            {
                ans = min(ans, (ll)cost);
                break; 
            }

            vector<int> v = { cur / 2, cur / 3, cur + 1, cur - 1 };

            for (const auto i : v)
            {
                if (i < 0 || i > 3000000) continue;

                const auto new_cost = cost + 1;
                if (visited[i] <= new_cost) continue;

                visited[i] = new_cost;
                q.emplace(new_cost, i);
            }
        }

        if (ans >= INF) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}