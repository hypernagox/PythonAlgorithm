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
int n, m, t;
vector<vector<int>> v1, v2;
vector<vector<int>>* Move(vector<vector<int>>& origin, vector<vector<int>>& dest)
{
    for (int k = 0; k < n / 2; ++k)
    {
        for (int i = k + 1; i < m - k - 0; ++i)
        {
            dest[k][i - 1 + 0] = origin[k][i + 0];
        }
    }
    for (int k = 0; k < n / 2; ++k)
    {
        for (int i = k + 0; i < m - k - 1; ++i)
        {
            dest[n - 1 - k][i + 1] = origin[n - 1 - k][i];
        }
    }
    for (int k = 0; k < m / 2; ++k)
    {
        for (int i = k + 0; i <n - k - 1; ++i)
        {
            dest[i + 1][k] = origin[i][k];
        }
    }
    for (int k = 0; k < m / 2; ++k)
    {
        for (int i = k + 1; i < n - k - 0; ++i)
        {
            dest[i - 1 + 0][m - 1 - k] = origin[i + 0][m - 1 - k];
        }
    }
    return &dest;
}
void Solve() noexcept
{
    cin >> n >> m >> t;
    v1.resize(n); v2.resize(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int x; cin >> x;
            v1[i].emplace_back(x);
            v2[i].emplace_back(x);
        }
    }
    vector<vector<int>>* res = nullptr;
    while (t--)
    { 
        v1.swap(v2);
        res = Move(v1, v2);
    }
    auto& r = *res;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << r[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}