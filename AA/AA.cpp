#include <iostream>
#include <algorithm>
#include <ranges>
using namespace std;
long long arr[5001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    ranges::sort(arr, arr + n);
    arr[n] = INT64_MAX / 2;
    long long res[3] = { arr[0],arr[1],arr[2] };
    uint64_t sum = UINT64_MAX;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            const long long temp = arr[i] + arr[j];
            auto iter = ranges::lower_bound(arr + j + 1, arr + n, -(temp));
            if (iter == arr+n || abs(*(iter - 1) + temp) <= abs(*iter + temp))
                if(iter != arr + j + 1)
                    --iter;
            const uint64_t val = abs(temp + *iter);
            if (sum > val) {
                sum = val;
                tie(res[0], res[1], res[2]) = { arr[i], arr[j], *iter };
            }
        }
    }
    for (const auto i : res)cout << i << ' ';
}