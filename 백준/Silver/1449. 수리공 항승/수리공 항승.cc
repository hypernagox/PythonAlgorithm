#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
int arr[1001];
int n, l;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    sort(arr, arr + n);
    int cur_start = arr[0];
    int cur_tape = l - 1;
    int ans = 1;
    for (int i = 1; i < n; ++i)
    {
        const auto len = arr[i] - cur_start;
        if (cur_tape >= len)
        {
            cur_tape -= len;
        }
        else
        {
            cur_tape = l - 1;
            ++ans;
        }
        cur_start = arr[i];
    }
    cout << ans;
}