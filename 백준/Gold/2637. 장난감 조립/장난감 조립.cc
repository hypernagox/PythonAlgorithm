#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;

static const int MAXN = 100;

int n, m;
vector<pair<int, int>> outEdges[MAXN + 1];
int indeg[MAXN + 1];

ll need[MAXN + 1][MAXN + 1];
bool isBasic[MAXN + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        outEdges[b].push_back({ a, c });
        indeg[a] += 1;
    }

    queue<int> q;

    for (int i = 1; i <= n; ++i)
    {
        if (indeg[i] == 0)
        {
            isBasic[i] = true;
            q.push(i);
            need[i][i] = 1;
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (const auto& [next, k] : outEdges[cur])
        {
            for (int b = 1; b <= n; ++b)
            {
                if (need[cur][b] != 0)
                {
                    need[next][b] += need[cur][b] * (ll)k;
                }
            }

            indeg[next] -= 1;
            if (indeg[next] == 0)
            {
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (isBasic[i])
        {
            cout << i << ' ' << need[n][i] << '\n';
        }
    }
}