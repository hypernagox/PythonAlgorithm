#include <iostream>
#include <algorithm>
#include <ranges>
using namespace std;
int arr[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    int res = 1 << 30;
    int sum = 0;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        while (sum >= m) {
            sum -= arr[s];
            res = min(res, i - s + 1);
            ++s;
        }
    }
    if (res == 1 << 30)
        cout << 0;
    else
        cout << res;
}