#include <bits/stdc++.h>
using namespace std;
struct Data
{
    int a;
    int b;
    const auto operator<(const Data& d)const{
        const auto s1 = (a+b);
        const auto s2 = (d.a + d.b);
        return s1 < s2;
    }
};
int solution(vector<vector<int>> scores) 
{
    const auto ta = scores[0][0];
    const auto tb = scores[0][1];
    vector<pair<int,int>> datas;
    for(const auto& v:scores)
    {
        datas.emplace_back(v[0],v[1]);
    }
    sort(datas.begin(), datas.end(),
        [](const pair<int,int>& x, const pair<int,int>& y)
        {
            if (x.first != y.first) return x.first > y.first;
            return x.second < y.second;
        });
    int max_b = -1;
    vector<Data> d;
    for(const auto [a,b]:datas)
    {
        if(max_b <= b)
        {
            max_b = b;
            Data D;
            D.a=a;
            D.b=b;
            d.emplace_back(D);
        }
        else
        {
            // 모든 점수가 낮음
            if(a==ta && b==tb)return -1;
        }
    }
    sort(d.begin(),d.end());
    Data target;
    target.a=ta;
    target.b=tb;
    return (d.end() - upper_bound(d.begin(),d.end(),target)) + 1;
}