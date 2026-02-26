#include <bits/stdc++.h>
using namespace std;

int solution(std::vector<int> a)
{
    unordered_map<int,int> freq;
    freq.reserve(a.size());
    for(const auto i: a)++freq[i];
    int answer = 0;
    for(int i = 0; i < a.size();++i)
    {
        const auto iter = freq.find(i);
        if(freq.end() == iter)continue;
        if(iter->second <= answer)continue;
        int temp = 0;
        for(int j = 0 ; j <a.size() - 1; ++j)
        {
            if((a[j]==i || a[j+1] ==i) && a[j] != a[j + 1])
            {
                answer = max(answer,++temp);
                ++j;
            }
        }
    }
    return answer * 2;
}