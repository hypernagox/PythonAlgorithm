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
    int num = 0;
    int recommanded = 0;
    int post_time = 0;
};
int n;
Data arr[21];
Data* GetData(const int num)
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i].num == num)
        {
            return &arr[i];
        }
    }
    return nullptr;
}
Data* GetData()
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i].num == 0)
        {
            return &arr[i];
        }
    }
    return nullptr;
}
void Solve()noexcept
{
    cin >> n;
    int m; cin >> m;
    vector<int> v;
    while (m--)
    {
        int x; cin >> x;
        v.emplace_back(x);
    }
    int cur_time = 0;
    int cur_cap = 0;
    for (const auto i : v)
    {
        if (const auto cur_data = GetData(i)) // 데이터있으면 추천수만
        {
            cur_data->recommanded++;
        }
        else
        {
            // 없는데 여유가 있으면
            if (cur_cap < n)
            {
                const auto d = GetData();
                d->num = i;
                d->post_time = cur_time;
                d->recommanded++;
                ++cur_cap;
            }
            else
            {
                // 여유가없다
                int min_v = 987654321;
                for (int i = 0; i < n; ++i)
                {
                    min_v = min(min_v, arr[i].recommanded);
                }
                int time = 987654321;
                int idx = 0;
                for (int i = 0; i < n; ++i)
                {
                    if (min_v == arr[i].recommanded)
                    {
                        if (time > arr[i].post_time)
                        {
                            time = arr[i].post_time;
                            idx = i;
                        }
                    }
                }
                arr[idx].num = i;
                arr[idx].recommanded = 1;
                arr[idx].post_time = cur_time;
            }
        }
        ++cur_time;
    }
    set<int> s;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i].num)
        {
            s.emplace(arr[i].num);
        }
    }
    for (const auto i : s)cout << i << ' ';
}
int main()
{
    FastIO();
    Solve();
}