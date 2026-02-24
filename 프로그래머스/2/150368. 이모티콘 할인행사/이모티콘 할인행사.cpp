#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
vector<int> sales;
vector<int> emo;
vector<int> emo_s;
vector<pi> u;
vector<int> answer;
void GO(const int cur)
{
    if(cur == emo.size())
    {
        int subscribe = 0;
        int total = 0;
        for(const auto [sal, lim] : u)
        {
            int sum = 0;
            bool flag = true;
            for(int i=0;i<emo.size();++i)
            {
                if(sal > emo_s[i])continue;
                sum += emo[i];
                if(sum >= lim)
                {
                    flag=false;
                    break;
                }
            }
            if(!flag)
            {
                sum = 0;
                ++subscribe;
            }
            total += sum;
        }
        if(answer[0] < subscribe)
        {
            answer[0]= subscribe;
            answer[1] = total;
        }
        else if(answer[0] == subscribe)
        {
            answer[1] = max(answer[1], total);
        }
        return;
    }
    for(int i=0;i<sales.size();++i)
    {
        const auto ori = emo[cur];
        emo[cur] = (emo[cur] / 100) * (100 - sales[i]);
        emo_s[cur] = sales[i];
        GO(cur + 1);
        emo[cur] = ori;
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    for(const auto& v: users)
    {
        u.emplace_back(v[0],v[1]);
    }
    sales.emplace_back(10);
    sales.emplace_back(20);
    sales.emplace_back(30);
    sales.emplace_back(40);
    answer.resize(2);
    emo = emoticons;
    emo_s.resize(emo.size());
    GO(0);
    return answer;
}