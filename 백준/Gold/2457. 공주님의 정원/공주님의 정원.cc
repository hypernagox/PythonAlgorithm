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
void Solve() noexcept
{
    int n; cin >> n;
    vector<pi> v; v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int a, b, c, d; cin >> a >> b >> c >> d;
        v.emplace_back(a * 100 + b, c * 100 + d);
    }
    sort(v.begin(), v.end());
    int end_time = 301;
    int cnt = 0;
    int idx = 0;
    // 시작시간이 end_time 이하 중 가장 늦게 끝나는거 찾기
    while (idx < v.size() && end_time < 1201)
    {
        int cur_end = end_time;
        while (idx < v.size() && v[idx].first <= end_time)
        {
            cur_end = max(cur_end, v[idx].second);
            ++idx;
        }
        if (end_time == cur_end)break;
        end_time = cur_end;
        ++cnt;
    }
    if (end_time < 1201)cout << 0;
    else cout << cnt;
}
int main()
{
    FastIO();
    Solve();
}