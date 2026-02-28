#include <bits/stdc++.h>
using namespace std;
int n_;
int w_;
int num_;
int GetCol(const int num, const bool flag)
{
    const auto normal = ((num - 1) % w_) + 1;
    return flag ? normal : w_ - normal + 1;
}
int GetFloor(const int num)
{
    return ((num - 1) / w_) + 1;
}
int solution(int n, int w, int num)
{
    int answer = 0;
    n_ = n;
    w_ = w;
    num_ = num;
    while(num <= n)
    {
        const int cur_floor = GetFloor(num);
        const int cur_col = GetCol(num, cur_floor & 1);
        if(cur_floor & 1)
        {
            num +=  w * 2 - (2*cur_col) + 1;
        }
        else
        {
            num += w * 2 - (2*(w- cur_col + 1)) + 1;
        }
       ++answer;
    }
    return answer;
}