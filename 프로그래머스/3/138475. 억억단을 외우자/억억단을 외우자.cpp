#include <bits/stdc++.h>
using namespace std;
int arr[5000001]; // 몇 번 등장?
int memo[5000001];
int E;
int GO(const int k)
{
    auto& ref = memo[k];
    if(~ref)return ref;
    if(k == E)
    {
        memo[k] = k;
        return ref = k;
    }
    const auto val = GO(k + 1);
    if(arr[k] < arr[val])
    {
        memo[k] = memo[k+1];
    }
    else
    {
        memo[k] = k;
    }
    return ref = memo[k];
}
vector<int> solution(int e, vector<int> starts)
{
    vector<int> answer;
    E = e;
    for(int i=1;i<=e;++i)
    {
        for(int j = i; j <= e; j += i)
        {
            ++arr[j];
        }
    }
    memset(memo,-1,sizeof(memo));
    for(const auto i : starts)
    {
        answer.emplace_back(GO(i));
    }
    return answer;
}