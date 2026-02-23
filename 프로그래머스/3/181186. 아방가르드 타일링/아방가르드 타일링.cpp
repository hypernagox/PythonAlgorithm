#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr const ll MOD = 1000000007;
ll memo[100001];
ll GO(const int k) 
{
    if (k < 0) return 0;
    if (k == 0) return 1;
    if (k == 1) return 1;
    if (k == 2) return 3;
    if (k == 3) return 10;
    if (k == 4) return 23;
    if (k == 5) return 62;
    auto& ref = memo[k];
    if (ref) return ref;
    const ll val = (GO(k - 1) + GO(k - 2) * 2 + GO(k - 3) * 6 + GO(k - 4)) % MOD;
    const ll minus_val = GO(k - 6) % MOD;
    return ref = (val - minus_val + MOD) % MOD;
}

int solution(int n) 
{
    //memset(memo, -1, sizeof(memo));
    return GO(n);
}