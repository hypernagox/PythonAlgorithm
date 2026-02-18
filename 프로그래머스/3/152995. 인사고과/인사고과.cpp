#include <bits/stdc++.h>
using namespace std;
struct Data
{
    int score_a;
    int score_b;
    const auto operator<(const Data& d)const{
        if(score_a == d.score_a)return score_b < d.score_b;
        return score_a > d.score_a;
    }
    Data(int a,int b):score_a{a},score_b{b}{}
};
int solution(vector<vector<int>> scores)
{
    const auto target = scores[0][0] + scores[0][1];
    // 한쪽은 내림차순, 한쪽은 오름차순
    // -> 점수하나 내림차순 시 동률일때 한쪽점수가 낮아도 일단 살가능성이있음
    vector<Data> v;
    for(const auto& e:scores)
    {
        v.emplace_back(e[0],e[1]);
    }
    sort(v.begin(),v.end());
    int max_b=-1;
    vector<int> vv;
    for(const auto [a,b]:v)
    {
        if(max_b <= b)
        {
            max_b = b;
            vv.emplace_back(a+b);
            
        }
        else
        {
            if(scores[0][0] == a && scores[0][1] == b)return -1;
        }
    }
    sort(vv.begin(),vv.end());
    return (vv.end() - upper_bound(vv.begin(),vv.end(),target)) + 1;
}