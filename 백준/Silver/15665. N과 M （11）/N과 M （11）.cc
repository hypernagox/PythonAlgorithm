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
int n, m;
int arr[8];
vector<int> ans;
set<vector<int>> s;
void GO()
{
    if (ans.size() == m)
    {
        s.emplace(ans);
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        ans.push_back(arr[i]);
        GO();
        ans.pop_back();
    }
}
void Solve() noexcept
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    GO();
    for (const auto& ss : s)
    {
        for (const auto num : ss)
        {
            cout << num << ' ';
        }
        cout << '\n';
    }
}
int main()
{
    FastIO();
    Solve();
}