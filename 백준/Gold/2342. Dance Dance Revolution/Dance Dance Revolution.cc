#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int n;
int arr[100001];
int memo[5][5][100001];
int GO(const int l, const int r, const int idx)
{
    if (idx == n)
    {
        return 0;
    }
    auto& ref = memo[l][r][idx];
    if (-1 != ref)return ref;
    const auto cur_target = arr[idx];
    if (l == cur_target || r == cur_target)
    {
       return ref = GO(l, r, idx + 1) + 1;
    }
    else
    {
        int a = INF;
        int b = INF;
        {
            const auto diff = abs(l - cur_target);
            if ((diff == 1 || diff == 3) && l)
            {
                a = GO(cur_target, r, idx + 1) + 3;
            }
            else if (diff == 2 && l)
            {
                a = GO(cur_target, r, idx + 1) + 4;
            }
            else
            {
                a = GO(cur_target, r, idx + 1) + 2;
            }
        }
        {
            const auto diff = abs(r - cur_target);
            if ((diff == 1 || diff == 3) && r)
            {
                b = GO(l, cur_target, idx + 1) + 3;
            }
            else if (diff == 2 && r)
            {
                b = GO(l, cur_target, idx + 1) + 4;
            }
            else
            {
                b = GO(l, cur_target, idx + 1) + 2;
            }
        }
        return ref = min(a, b);
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < 100001; ++i)
    {
        cin >> arr[i];
        if (arr[i] == 0)break;
        ++n;
    }
    cout << GO(0, 0, 0);
}