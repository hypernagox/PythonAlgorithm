#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
string str;
int palin_dp[2501][2501];
int memo[2501];
bool IsPailn(const int l, const int r)
{
    if (l >= r)return true;
    auto& ref = palin_dp[l][r];
    if (-1 != ref)return ref;
    if (str[l] == str[r])
    {
        return ref = IsPailn(l + 1, r - 1);
    }
    else
    {
        return ref = false;
    }
}
int GO(const int cur)
{
    if (cur >= str.size())return 0;
    auto& ref = memo[cur];
    if (ref)return ref;
    int a = INF;
    for (int i = 0; i + cur < str.size(); ++i)
    {
        if (IsPailn(cur, cur + i))
        {
            a = min(a, GO(cur + i + 1) + 1);
        }
    }
    return ref = a;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(palin_dp, -1, sizeof(palin_dp));
    cin >> str;
    cout << GO(0);
}