#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<int> tangerine)
{
    int answer = 0;
    map<int,int> freq;
    for(const auto i :tangerine)
    {
        ++freq[i];
    }
    vector<int> r;
    for(const auto [val, f] : freq)
    {
        r.emplace_back(f);
    }
    sort(r.begin(),r.end(),greater<int>{});
    int cnt = 0;
    for(int i=0;i<r.size();++i)
    {
        cnt += r[i];
        if(cnt >= k)
        {
            answer = i + 1;
            break;
        }
    }
    return answer;
}