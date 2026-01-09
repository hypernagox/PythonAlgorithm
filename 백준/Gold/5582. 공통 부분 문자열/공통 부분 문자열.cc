#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
string s1, s2;
int memo[4001][4001];
int GO(const int i1, const int i2)
{
    if (i1 == s1.size())return 0;
    if (i2 == s2.size())return 0;
    auto& ref = memo[i1][i2];
    if (~ref)return ref;
    int res = 0;
    if (s1[i1] == s2[i2])
    {
        res = GO(i1 + 1, i2 + 1) + 1;
    }
    else
    {
        res = 0;
    }
    return ref = res;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s1 >> s2;
    int res = 0;
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < s1.size(); ++i)
    {
        for (int j = 0; j < s2.size(); ++j)
        {
            res = max(res, GO(i, j));
        }
    }
    cout << res;
}