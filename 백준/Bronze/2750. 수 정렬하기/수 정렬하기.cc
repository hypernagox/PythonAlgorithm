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
int Partition(vector<int>& arr, const int left, const int right)
{
    const int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; ++j)
    {
        if (arr[j] < pivot)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}
void QuickSort(vector<int>& arr, const int left, const int right)
{
    if (left < right)
    {
        const int pivot = Partition(arr, left, right);
        QuickSort(arr, left, pivot - 1);
        QuickSort(arr, pivot + 1, right);
    }
}
void Sort(vector<int>& arr, const int left, const int right)
{
    QuickSort(arr, left, right);
}
void Solve() noexcept
{
    int n; cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        v.emplace_back(x);
    }
    Sort(v, 0, n - 1);
    for (const auto i : v)cout << i << '\n';
}
int main()
{
    FastIO();
    Solve();
}