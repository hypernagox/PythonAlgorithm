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
struct DisjointSet
{
    vector<int> parents;
    DisjointSet(const int n) :parents(n + 1)
    {
        iota(parents.begin(), parents.end(), 0);
    }
    int FindParent(const int cur)
    {
        auto& parent = parents[cur];
        if (cur == parent)return cur;
        return parent = FindParent(parent);
    }
    bool Union(int a, int b)
    {
        a = FindParent(a);
        b = FindParent(b);
        if (a == b)return false;
        if (a > b)swap(a, b);
        parents[b] = a;
        return true;
    }
};
void Solve() noexcept
{
    int t; cin >> t;
    string str = "Scenario 0:\n";
    int cnt = 1;
    while (t--)
    {
        int n, k; cin >> n >> k;
        DisjointSet ds{ n };
        while (k--)
        {
            int a, b; cin >> a >> b;
            ds.Union(a, b);
        }
        int m; cin >> m;
        *next(++str.rbegin()) = (cnt++) + '0';
        cout << str;
        while (m--)
        {
            int a, b; cin >> a >> b;
            cout << (ds.FindParent(a) == ds.FindParent(b)) << '\n';
        }
        cout << '\n';   
    }
}
int main()
{
    FastIO();
    Solve();
}