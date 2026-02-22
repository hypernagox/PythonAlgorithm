#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) 
{
    vector<int> answer;answer.reserve(queries.size());
    map<int,vector<string>> words_map;
    map<int,vector<string>> words_map_r;
    for(auto& w : words)
    {
        words_map[w.size()].emplace_back(w);
        reverse(w.begin(),w.end());
        words_map_r[w.size()].emplace_back(move(w));
    }
    for(auto& [num, v]:words_map)
    {
        sort(v.begin(),v.end());
    }
    for(auto& [num, v]:words_map_r)
    {
        sort(v.begin(),v.end());
    }
    for(auto& q: queries)
    {
        if(q.front() != '?')
        {
            const auto& w = words_map[q.size()];
            string temp1 = q;
            string temp2 = q;
            for(auto& c:temp1)
            {
                if(c=='?')c='a' - 1;
            }
            for(auto& c:temp2)
            {
                if(c=='?')c='z' + 1;
            }
            const auto a = lower_bound(w.begin(),w.end(),temp1);
            const auto b = upper_bound(w.begin(),w.end(),temp2);
            answer.emplace_back(b-a);
        }
       else
       {
            const auto& w = words_map_r[q.size()];
            reverse(q.begin(),q.end());
            string temp1 = q;
            string temp2 = q;
            for(auto& c:temp1)
            {
                if(c=='?')c='a' - 1;
            }
            for(auto& c:temp2)
            {
                if(c=='?')c='z' + 1;
            }
            const auto a = lower_bound(w.begin(),w.end(),temp1);
            const auto b = upper_bound(w.begin(),w.end(),temp2);
            answer.emplace_back(b-a);
       }
    }
    return answer;
}