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
constexpr const int LIM = 4000001;
bool IsPrime[LIM + 1];
vector<int> primes;
void Init()
{
    fill(begin(IsPrime), end(IsPrime), 1);
    IsPrime[0] = IsPrime[1] = 0;
    for (int i = 2; i <= (int)sqrt(LIM); ++i)
    {
        if (!IsPrime[i])continue;
        for (int j = i + i; j <= LIM; j += i)
        {
            IsPrime[j] = 0;
        }
    }
    for (int i = 2; i <= (LIM); ++i)
    {
        if (!IsPrime[i])continue;
        primes.emplace_back(i);
    }
}
void Solve()noexcept
{
    Init();
    int n; cin >> n;
    ll res = 0;
    int sum = 0;
    int b = 0;
    int e = 0;
    while (e < primes.size() || b < primes.size())
    {
        if (sum >= n)sum -= primes[b++];
        else if (e < primes.size())sum += primes[e++];
        else break;
        if (sum == n)++res;
    }
    cout << res;
}
int main()
{
    FastIO();
    Solve();
}
