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
bool visited[9];
int n, m;
string nums;
void GO(const int cur)
{
    if (cur == m)
    {
        cout << nums << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i])continue;
        visited[i] = 1;
        nums.push_back(i + '0');
        nums.push_back(' ');
        GO(cur + 1);
        nums.pop_back();
        nums.pop_back();
        visited[i] = 0;
    }
}
void Solve()noexcept
{
    cin >> n >> m;
    GO(0);
}
int main()
{
    FastIO();
    Solve();
}