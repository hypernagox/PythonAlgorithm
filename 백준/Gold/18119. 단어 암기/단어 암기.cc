#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int words[10001]{};
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        string temp; cin >> temp;
        for (const auto ch : temp)
        {
            words[i] |= (1 << (ch - 'a'));
        }
    }
    int cur_knows = 0;
    for (int i = 0; i < 26; ++i)
    {
        cur_knows |= (1 << (i));
    }
    while (m--)
    {
        int ans = 0;
        int o; char x; cin >> o >> x;
        const int target = (1 << (x - 'a'));
        cur_knows ^= target;
        for (int i = 0; i < n; ++i)
        {
            ans += (words[i] & cur_knows) == words[i];
        }
        cout << ans << '\n';
    }
}