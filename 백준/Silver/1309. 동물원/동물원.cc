#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int n;
int memo[200002][3];
int GO(const int i,const int state)
{
    if (i == n)return 1;
    auto& ref = memo[i][state];
    if (~ref)return ref;
    // 배치를 안한다
    int res = 0;

   // res += GO(i + 1, 0) + 1;

    // 왼쪽이었다면
    if (state == 1)
    {
        // 오른쪽 배치
        res += GO(i + 1, 0)% 9901 + GO(i + 1, 2) % 9901;
    }
    // 오른쪽이었다면
    else if (state == 2)
    {
        // 왼쪽배치
        res += GO(i + 1, 0) % 9901 + GO(i + 1, 1)% 9901;
    }
    else
    {
        // 없었다면 다가능
        res += GO(i + 1, 0)% 9901 + GO(i + 1, 2)% 9901 + GO(i + 1, 1)% 9901;
    }
    return ref = res % 9901;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    memset(memo, -1, sizeof(memo));
    cout << GO(0, 0);
}