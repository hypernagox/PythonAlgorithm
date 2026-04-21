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
class Heap
{
public:
    void Add(const int val)
    {
        arr[size] = val;
        HeapifyUp(size);
        ++size;
    }
    int Pop()
    {
        const auto target = arr[0];
        arr[0] = arr[size - 1];
        --size;
        HeapifyDown(0);
        return target;
    }
private:
    void HeapifyUp(const int idx)
    {
        int i = idx;
        while (i > 0 && arr[i] > arr[(i - 1) / 2])
        {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    void HeapifyDown(const int idx)
    {
        int i = idx;
        while (i < size)
        {
            int largest = i;
            int left = i * 2 + 1;
            int right = i * 2 + 2;
            if (left < size && arr[largest] < arr[left])largest = left;
            if (right < size && arr[largest] < arr[right])largest = right;
            if (largest == i)break;
            swap(arr[largest], arr[i]);
            i = largest;
        }
    }
private:
    static constexpr const int MAX_SIZE = 1001;
    int size = 0;
    int arr[MAX_SIZE];
};
void HeapifyDown(vector<int>& arr, const int heap_size, int index)
{
    while (true)
    {
        int largest = index;
        const int left = index * 2 + 1;
        const int right = index * 2 + 2;

        if (left < heap_size && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < heap_size && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest == index)
        {
            break;
        }

        swap(arr[index], arr[largest]);
        index = largest;
    }
}

void BuildMaxHeap(vector<int>& arr)
{
    const int n = static_cast<int>(arr.size());
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        HeapifyDown(arr, n, i);
    }
}

void HeapSort(vector<int>& arr)
{
    const int n = static_cast<int>(arr.size());

    BuildMaxHeap(arr);

    for (int i = n - 1; i > 0; --i)
    {
        swap(arr[0], arr[i]);
        HeapifyDown(arr, i, 0);
    }
}
void Sort(vector<int>& arr, const int left, const int right)
{
    //QuickSort(arr, left, right);
   // MergeSort(arr, left, right);

    Heap h;
    for (int i = 0; i < arr.size(); ++i)
    {
        h.Add(arr[i]);
    }
    vector<int> temp;
    for (int i = 0; i < arr.size(); ++i)
    {
        temp.emplace_back(h.Pop());
    }
    reverse(temp.begin(), temp.end());
    temp.swap(arr);
    //HeapSort(arr);
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