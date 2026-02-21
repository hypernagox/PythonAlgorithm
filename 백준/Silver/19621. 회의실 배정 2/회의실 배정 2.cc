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
    int num;
};
Data arr[100001];
int n;
int GO(const int idx, const int last_idx)
{
    if (idx == n)return 0;
    int a = 0;
    int b = 0;
    if ((-1 == last_idx) || (arr[last_idx].end <= arr[idx].start))
    {
        // 선택 해본다.
        a = GO(idx + 1, idx) + arr[idx].num;
    }
    b = GO(idx + 1, last_idx); // 선택하지 않고 넘긴다
    return max(a, b);
}
void Solve()noexcept
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].start >> arr[i].end >> arr[i].num;
    }
    sort(arr, arr + n, [](auto a, auto b) {
        if (a.end == b.end)return a.start < b.start;
        return a.end < b.end;
        });
    cout << GO(0, -1);
}
int main()
{
    FastIO();
    Solve();
}
