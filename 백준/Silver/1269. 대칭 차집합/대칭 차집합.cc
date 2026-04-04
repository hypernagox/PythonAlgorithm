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
void Solve() noexcept
{
    int n, m; cin >> n >> m;
    vector<int> A, B; A.reserve(n); B.reserve(m);
    for (int i = 0; i < n; ++i) 
    {
        int x; cin >> x;
        A.emplace_back(x);
    }
    for (int i = 0; i < m; ++i)
    {
        int x; cin >> x;
        B.emplace_back(x);
    }
    ranges::sort(A);
    ranges::sort(B);
    int a_size = n;
    int b_size = m;
    for (int i = 0; i < n; ++i)
    {
        b_size -= ranges::binary_search(B, A[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        a_size -= ranges::binary_search(A, B[i]);
    }
    cout << a_size + b_size;
}
int main()
{
    FastIO();
    Solve();
}