#include <bits/stdc++.h>
using namespace std;
const int MAX_SUM = 500000;
int arr[55];
int counts[10001];
int n;
int real_n;
bool IsPrime[MAX_SUM + 1];
vector<long long> memo[55];
int max_possible_sum[55];
void Init()
{
    fill(IsPrime, IsPrime + MAX_SUM + 1, true);
    IsPrime[0] = IsPrime[1] = false;
    for (int i = 2; i * i <= MAX_SUM; ++i)
    {
        if (!IsPrime[i]) continue;
        for (int j = i * i; j <= MAX_SUM; j += i)
        {
            IsPrime[j] = false;
        }
    }
}
long long GO(const int idx, const int cur_money)
{
    if (idx == n)
    {
        return IsPrime[cur_money] ? 1 : 0;
    }
    long long& ref = memo[idx][cur_money];
    if (ref != -1) return ref;
    long long res = 0;
    int price = arr[idx];
    int limit = counts[price];
    for (int k = 0; k <= limit; ++k)
    {
        res += GO(idx + 1, cur_money + (price * k));
    }
    return ref = res;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Init();
    cin >> real_n;
    set<int> s;
    int unique_idx = 0;
    for (int i = 0; i < real_n; ++i)
    {
        int x; cin >> x;
        counts[x]++;
        if (s.find(x) == s.end()) {
            s.insert(x);
            arr[unique_idx++] = x;
        }
    }
    n = unique_idx;
    int current_max = 0;
    memo[0].assign(1, -1);
    for (int i = 0; i < n; ++i)
    {
        int price = arr[i];
        int count = counts[price];
        current_max += price * count;
        memo[i + 1].assign(current_max + 1, -1);
    }
    cout << GO(0, 0);
}