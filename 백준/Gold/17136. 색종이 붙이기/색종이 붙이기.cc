#include <bits/stdc++.h>
using namespace std;
constexpr const int INF = 987654321;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
int paper[11][11];
int items[5]{ 5,5,5,5,5 };
bool IsFinish()
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (paper[i][j])return false;
        }
    }
    return true;
}
bool CheckFill(const int y, const int x, const int size)
{
    for (int i = y; i < y + size; ++i)
    {
        for (int j = x; j < x + size; ++j)
        {
            if (!paper[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
void TryFill(const int y, const int x, const int size, const bool fill_flag)
{
    for (int i = y; i < y + size; ++i)
    {
        for (int j = x; j < x + size; ++j)
        {
            paper[i][j] = fill_flag;
        }
    }
}
int ans = INF;
void GO(const int cur_count)
{
    if (cur_count >= ans)
    {
        return;
    }
    if (IsFinish())
    {
        ans = min(ans, cur_count);
        return;
    }
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (paper[i][j])
            {
                for (int size = 1; size <= 5; ++size)
                {
                    if (i + size > 10 || j + size > 10)continue;
                    if (items[size - 1] && CheckFill(i,j,size))
                    {
                        --items[size - 1];
                        TryFill(i, j, size, 0);
                        GO(cur_count + 1);
                        TryFill(i, j, size, 1);
                        ++items[size - 1];
                    }
                }
                return;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cin >> paper[i][j];
        }
    }
    GO(0);
    if (ans == INF)cout << -1;
    else cout << ans;
}