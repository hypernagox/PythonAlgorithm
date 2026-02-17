#include <bits/stdc++.h>
using namespace std;
int appear[5000001];
int memo[5000001];
int E;
int GO(const int idx)
{
    if(idx == E)
    {
        return idx;
    }
    auto& ref = memo[idx];
    if(~ref)return ref;
    const auto val = GO(idx + 1); // idx + 1 의 정답
    return ref = appear[idx] >= appear[val] ? idx : val; // 지금 빈도가 더 크면 지금 값을 리턴
}
vector<int> solution(int e, vector<int> starts)
{
    vector<int> answer;
    E = e;
    for(int i=1;i<=e;++i)
    {
        for(int j=i;j<=e; j+=i)
        {
            ++appear[j];
        }
    }
    memset(memo,-1,sizeof(memo));
    for(const auto i :starts)
    {
        answer.emplace_back(GO(i));
    }
    return answer;
}