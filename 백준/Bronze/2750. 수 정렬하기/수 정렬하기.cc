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
    const auto pivot = arr[left];
    int l = left + 1;
    int r = right;
    while (l <= r)
    {
        while (l <= right && arr[l] < pivot) { ++l; }
        while (r >= left + 1 && arr[r] > pivot) { --r; }
        if (l >= r)break;
        swap(arr[l], arr[r]);
        ++l; --r;
    }
    swap(arr[r], arr[left]);
    return r;
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
void Partition2(vector<int>& arr, const int left, const int right)
{
    const auto mid = (left + right) / 2;
    const auto left_size = mid - left + 1;
    const auto right_size = right - mid;
    vector<int> L(left_size);
    vector<int> R(right_size);
    for (int i = 0; i < left_size; ++i)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < right_size; ++i)
    {
        R[i] = arr[mid + 1 + i];
    }
    int l = 0;
    int r = 0;
    int k = left;
    while (l < left_size && r < right_size)
    {
        if (L[l] <= R[r])
        {
            arr[k++] = L[l++];
        }
        else
        {
            arr[k++] = R[r++];
        }
    }
    while (l < left_size){ arr[k++] = L[l++]; }
    while (r < right_size) { arr[k++] = R[r++]; }
}
void MergeSort(vector<int>& arr, const int left, const int right)
{
    if (left < right)
    {
        const auto mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Partition2(arr, left, right);
    }
}
void Sort(vector<int>& arr, const int left, const int right)
{
    //QuickSort(arr, left, right);
    MergeSort(arr, left, right);
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