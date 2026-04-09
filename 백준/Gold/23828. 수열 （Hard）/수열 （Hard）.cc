#include <bits/stdc++.h>
using namespace std;
void FastIO()noexcept { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
constexpr const int INF = static_cast<int>(1e9) + 1;
constexpr const int MIN_INF = -INF;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
vector<int> v;
map<int, int> mm;
int n, m;
constexpr const ll MOD = 1000000007;
ll memo[1001][1001];
ll GO(const int N, const int M)
{
    if (N == n)
    {
        return m == M;
    }
    if (M >= m)
    {
        return 1;
    }
    auto& ref = memo[N][M];
    if (~ref)return ref;
    // 뽑는다
    const auto a = (GO(N + 1, M + 1) * v[N] * mm[v[N]]) % MOD;
    // 안뽑는다
    const auto b = GO(N + 1, M) % MOD;
    return ref = (a + b)  % MOD;
}
void Solve() noexcept
{
     cin >> n >> m;
     for (int i = 0; i < n; ++i)
     {
         int x; cin >> x;
         v.emplace_back(x);
         ++mm[x];
     }
     sort(v.begin(), v.end());
     v.erase(unique(v.begin(), v.end()),v.end());
     n = (int)v.size();
     memset(memo, -1, sizeof(memo));
     cout << GO(0, 0);
}
int main()
{
    FastIO();
    Solve();
}