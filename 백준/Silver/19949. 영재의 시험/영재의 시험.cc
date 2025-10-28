#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
int arr[10];
int ans[10];
long long res = 0;
void GO(const int cur_depth, const int prev,const int prev_count)
{
    if (cur_depth == 10)
    {
        int sum = 0;
        for (int i = 0; i < 10; ++i)
        {
            sum += (arr[i] == ans[i]);
        }
        res += (sum >= 5);
        return;
    }
    for (int i = 1; i <= 5; ++i)
    {
        if (prev == i)
        {
            if (prev_count >= 2)
            {
                continue;
            }
            else
            {
                arr[cur_depth] = i;
                GO(cur_depth + 1, i, prev_count + 1);
                arr[cur_depth] = 0;
            }
        }
        else
        {
            arr[cur_depth] = i;
            GO(cur_depth + 1, i, 1);
            arr[cur_depth] = 0;
        }
    }
}
int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    for (int i = 0; i < 10; ++i)cin >> ans[i];
    GO(0, 0, 0);
    cout << res;
}