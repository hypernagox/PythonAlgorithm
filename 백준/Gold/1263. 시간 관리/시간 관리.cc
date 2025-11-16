#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Data
{
    ll require_time;
    ll dead_line;
    const auto operator<(const Data& d) const noexcept
    {
        if (dead_line == d.dead_line)
        {
            return require_time < d.require_time;
        }
        return dead_line < d.dead_line; // 마감시간 오름차순
    }
};

int n;
vector<Data> v;

bool Check(const ll start)
{
    ll cur_time = start;
    for (const auto& job : v)
    {
        cur_time += job.require_time;
        if (cur_time > job.dead_line)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        Data d;
        cin >> d.require_time >> d.dead_line;
        v.emplace_back(d);
    }

    sort(v.begin(), v.end());

    // 먼저 아예 0에서 시작해도 불가능한지 체크
    if (!Check(0))
    {
        cout << -1;
        return 0;
    }

    // r: 가능한 시작 시각의 상한 + 1 (exclusive)
    ll r = 0;
    for (const auto& job : v)
    {
        r = max(r, job.dead_line);
    }
    ++r; // [0, r) 구간에서 이진 탐색

    ll l = 0;
    ll res = 0;

    while (l < r)
    {
        ll mid = (l + r) / 2;
        if (Check(mid))
        {
            res = mid;      // mid까지는 가능
            l = mid + 1;    // 더 늦게 시작해볼까?
        }
        else
        {
            r = mid;        // mid는 불가능, 더 이르게
        }
    }

    cout << res;
    return 0;
}
