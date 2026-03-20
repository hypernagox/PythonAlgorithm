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
int n;
int score[21][21];
vector<int> v1, v2;
int GetScore(const vector<int>& v)
{
    int s = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v.size(); ++j)
        {
            s += score[v[i]][v[j]];
        }
    }
    return s;
}
int ans = INF;
void GO(const int cur)
{
    if (cur == n)
    {
        ans = min(ans, abs(GetScore(v1) - GetScore(v2)));
        return;
    }
    // 1번팀으로 갔을때
    v1.emplace_back(cur);
    GO(cur + 1);
    v1.pop_back();

    // 2번팀으로 갔을때
    v2.emplace_back(cur);
    GO(cur + 1);
    v2.pop_back();
}
void Solve() noexcept
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> score[i][j];
        }
    }
    GO(0);
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}