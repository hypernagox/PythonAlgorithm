#include <bits/stdc++.h>
using namespace std;
int solution(vector<string> words) 
{
    sort(words.begin(),words.end());
    vector<int> result(words.size(), 0);
    for(int i=0;i<words.size()-1;++i)
    {
        const auto [it1,it2] = mismatch(words[i+1].begin(),words[i+1].end(),words[i].begin(),words[i].end());
        const auto n1 = (int)distance(words[i + 1].begin(),it1);
        const auto n2 = (int)distance(words[i].begin(),it2);
        const int need = n1 + 1;
        const auto a=(int)words[i].size();
        const auto b=(int)words[i+1].size();
        result[i]     = max(result[i],     min(a, need));
        result[i + 1] = max(result[i + 1], min(b, need));
    }
    return accumulate(result.begin(),result.end(),0);
}