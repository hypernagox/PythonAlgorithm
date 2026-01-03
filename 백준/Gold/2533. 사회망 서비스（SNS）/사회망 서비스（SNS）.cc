#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
vector<int> adj[1000001];
//bool visited[1000001];
int memo[1000001][2];
int n;
int GO(const int cur,const bool early,const int prev)
{
    auto& ref = memo[cur][early];
    if (-1 != ref)return ref;
    int res = 0;
   // visited[cur] = true;
    if (!early)
    {
        // 내가 얼리어답터가 아니라면 자식이 싹다 얼리어답터
        for (const auto next : adj[cur])
        {
            //if (visited[next])continue;
            if (prev == next)continue;
            res += GO(next, true,cur);
        }
    }
    else
    {
        // 내가 얼리어답터면 자식이 얼리어답터일수도 아닐수도
        for (const auto next : adj[cur])
        {
           // if (visited[next])continue;
            if (prev == next)continue;
            const auto m = min(GO(next, false,cur), GO(next, true,cur));
            res += m;
        }
    }
    //visited[cur] = false;
    return ref = res + early;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    n -= 1;
    while (n--)
    {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    memset(memo, -1, sizeof(memo));
    cout << min(GO(1, 0,1), GO(1, 1,1));
}