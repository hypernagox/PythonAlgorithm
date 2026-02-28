#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<int>(1e9);
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int n, k;
int arr[101];
map<int, queue<int>> idxm; // 등장 인덱스
void Solve()noexcept
{
    cin >> n >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> arr[i];
        idxm[arr[i]].emplace(i + 1);
    }
    int res = 0;
    map<int, int> idx2item;
    set<int> s;
    for (int i = 0; i < k; ++i)
    {
        const auto iter = s.find(arr[i]);
        if (s.end() != iter)
        {
            idxm[arr[i]].pop();
            const auto next_idx = idxm[arr[i]].empty() ? -INF + i: -idxm[arr[i]].front();
            idx2item.erase(-i);
            idx2item.emplace(next_idx, arr[i]);
            continue;
        }
        if (s.size() == n)
        {
            ++res;
            const auto [idx, num] = *idx2item.begin();
            s.erase(num);
            idx2item.erase(idx2item.begin());
        }
        idxm[arr[i]].pop();
        const auto next_idx = idxm[arr[i]].empty() ? -INF + i: -idxm[arr[i]].front();
        idx2item.emplace(next_idx, arr[i]);
        s.emplace(arr[i]);
    }
    cout << res;
}
int main()
{
    FastIO();
    Solve();
}