#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
map<string, vector<string>> adj;
string king;
int n, m;
double GO(const string& cur)
{
    if (cur == king)return 1.0;
    double res = 0.;
    for (const auto& parent : adj[cur])
    {
        res += GO(parent);
    }
    return res / 2.;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> king;
    vector<string> targets;
    for (int i = 0; i < n; ++i)
    {
        string baby, m, f; cin >> baby >> m >> f;
        adj[baby].emplace_back(move(m));
        adj[baby].emplace_back(move(f));
    }
    for (int i = 0; i < m; ++i)
    {
        string temp; cin >> temp;
        targets.emplace_back(move(temp));
    }
    double max_val = -1;
    string res = {};
    for (const auto& t : targets)
    {
        const auto v = GO(t);
        if (max_val < v)
        {
            max_val = v;
            res = t;
        }
    }
    cout << res;
}