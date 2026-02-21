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
struct Data
{
    int start;
    int end;
};
Data arr[100001];
void Solve()noexcept
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].start >> arr[i].end;
    }
    ranges::sort(arr, arr + n, [](const auto& a, const auto& b) {
        if (a.end == b.end)return a.start < b.start;
        return a.end < b.end;
        });
    int ans = 1;
    int cur_end = arr[0].end;
    for (int i = 1; i < n; ++i)
    {
        if (cur_end <= arr[i].start)
        {
            ++ans;
            cur_end = arr[i].end;
        }
    }
    cout << ans;
}
int main()
{
    FastIO();
    Solve();
}
