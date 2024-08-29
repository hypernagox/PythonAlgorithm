#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
using namespace std;
int arr1[100001];
int arr2[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int m = 0;
    int p = 0;
    ranges::fill(arr2, 99876543210);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x < 0)
            arr1[m++] = x;
        else
            arr2[p++] = x;
    }
    arr1[m] = -(1 << 30);
    long long res = 99876543210;
    pair<int, int> ans;
    for (int i = 0; i < m; ++i) {
        auto iter = ranges::lower_bound(arr2, arr2 + p, -arr1[i]);
        if (*iter != arr2[0]) {
            if (abs(*iter + arr1[i]) > abs(*(iter - 1) + arr1[i])) {
                --iter;
            }
        }
        const auto v1 = abs(*iter + arr1[i]);
        const auto v2 = abs(arr1[i] + arr1[i + 1]);
        if (v1 < v2) {
            if (res > v1) {
                res = v1;
                ans = { arr1[i],*iter };
            }
        }
        else {
            if (res > v2) {
                res = v2;
                ans = { arr1[i],arr1[i + 1] };
            }
        }

    }
    for (int i = 0; i < p - 1; ++i) {
        if (res > arr2[i] + arr2[i + 1]) {
            res = arr2[i] + arr2[i + 1];
            ans = { arr2[i],arr2[i + 1] };
        }
    }
    cout << ans.first << ' ' << ans.second;
}