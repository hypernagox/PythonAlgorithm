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
int A[200000];
int B[200000];
void Solve() noexcept
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i)cin >> A[i];
    for (int i = 0; i < m; ++i)cin >> B[i];
    sort(A, A + n);
    sort(B, B + m);
    int a_size = n;
    int b_size = m;
    for (int i = 0; i < n; ++i)
    {
        b_size -= binary_search(B, B + m, A[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        a_size -= binary_search(A, A + n, B[i]);
    }
    cout << a_size + b_size;
}
int main()
{
    FastIO();
    Solve();
}