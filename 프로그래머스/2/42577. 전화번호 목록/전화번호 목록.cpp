#include <bits/stdc++.h>
using namespace std;
bool solution(vector<string> phone_book)
{
    vector<string> v[10];
    for(auto& s: phone_book)
    {
        v[s.front()-'0'].emplace_back(move(s));
    }
    for(auto& vv: v)
    {
        sort(vv.begin(),vv.end());
    }
    for(const auto& vv: v)
    {
        if(vv.empty())continue;
        for(int i=0;i<vv.size()-1;++i)
        {
            const auto& s1 = vv[i];
            const auto& s2 = vv[i+1];
            //cout<<s1<<" "<<s2<<endl;
            //cout<<s2.substr(s1.size())<<endl;
            if(s2.substr(0,s1.size())==s1)return false;
        }
    }
    return true;
}