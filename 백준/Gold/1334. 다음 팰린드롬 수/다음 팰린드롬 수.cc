#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
void Reverse(string& num)
{
    int n = (int)num.size();
    for (int i = 0; i < n / 2; ++i)
    {
        num[n - 1 - i] = num[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string num; cin >> num;
    string orig = num;
    Reverse(num);
    if (num <= orig)
    {
        int mid = ((int)num.size() - 1) / 2;
        int cur = mid;
        while (cur >= 0 && num[cur] == '9')
        {
            num[cur] = '0';
            --cur;
        }
        if (cur >= 0)
        {
            num[cur] += 1;
        }
        else
        {
            num = "1" + num;
            num.back() = '1';
        }
        Reverse(num);
    }
    cout << num;
}
