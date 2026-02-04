#include <bits/stdc++.h>
using namespace std;
long long memo[101][101];
constexpr const long long MOD = 1000000007;
long long GO(const long long n, const long long cnt)
{
    if (cnt < 0 || cnt > n) return 0;
    if (n == 0) return (cnt == 0) ? 1 : 0;
    auto &ref = memo[n][cnt];
    if (~ref) return ref;
    // count개는 일단 n - 1 에 count - 1개 보이는 상태에서 제일큰거 추가하면된다.
    const auto a = GO(n-1,cnt-1) % MOD;
    // n - 1개에서 count만큼 보일때
    const auto b = (2LL*n% MOD - 2LL) % MOD *GO(n-1LL,cnt) %MOD;
    return ref = (a + b)%MOD;
}
int solution(int n, int count)
{
    memset(memo,-1,sizeof(memo));
    return GO(n,count);
}