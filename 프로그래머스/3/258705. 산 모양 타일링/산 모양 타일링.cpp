#include <bits/stdc++.h>
using namespace std;
vector<int> top;
int N;
constexpr const int MOD = 10007;
int memo[100001][2];
int GO(const int idx,const bool right_flag)
{
    if(idx == N)
    {
        if(right_flag)return 1;
        else return top[idx] ? 3 : 2;
    }
    auto& ref = memo[idx][right_flag];
    if(ref)return ref;
    if(right_flag)
    {
        return ref = (GO(idx+1,0) + GO(idx+1,1)) % MOD;
    }
    else
    {
        if(top[idx])
        {
           return ref = (GO(idx+1,1) * 2 + GO(idx+1,0) * 3) % MOD;
        }
        else
        {
           return ref = (GO(idx+1,1) + GO(idx+1,0) * 2) % MOD;
        }
    }
    
    
   
}
int solution(int n, vector<int> tops) 
{
    N = n - 1;
    top.swap(tops);
    return (GO(0,0) + GO(0,1))%MOD;
}