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
    int ans = 0;
    int cover_end = -1;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > cover_end) 
        {
            ++ans;
            cover_end = arr[i] + l - 1;
        }
    }
    cout << ans;
}