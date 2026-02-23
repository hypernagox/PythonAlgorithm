#include <bits/stdc++.h>
using namespace std;
const char aeiou[]{"AEIOU"};
string W;
int answer = 0;
int num;
void GO(string& cur)
{
    if(cur==W)answer=num;
    //cout<<cur<<endl;
    ++num;
    if(cur.size() == 5)
    {
        return;
    }
    for(int i=0;i<5;++i)
    {
        cur.push_back(aeiou[i]);
        GO(cur);
        cur.pop_back();
    }
}
int solution(string word) 
{
    
    string cur{""};
    W=word;
    GO(cur);
    return answer;
}