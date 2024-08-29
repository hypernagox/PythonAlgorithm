#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
using namespace std;
int arr[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; ++i)cin >> arr[i];
    ranges::sort(arr, arr + n);
    int s = 0;
    int e = n - 1;
    pair<int, int> res;
    long long sum = 99876543210;
    while (s < e) {
        const int temp = arr[s] + arr[e];
        const int abstemp = abs(temp);
        if (sum > abstemp) {
            sum = abstemp;
            res = { arr[s],arr[e] };
        }
        if (temp > 0)
            --e;
        else
            ++s;
    }
    cout << res.first << ' ' << res.second;
}