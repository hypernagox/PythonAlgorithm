#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) 
{
    map<string,int> m;
    //string c="A";
    for(int i=1;i<=26;++i)
    {
       // cout<<string(1,'A'+i-1)<<endl;
        m[string(1,'A'+i-1)]=i;
    }
    vector<int> answer;
    int cur_num = 27;
    int pos = 0;
    while(pos < msg.size())
    {
        int len = 1;
        string w(1, msg[pos]);
         while (pos + len <= msg.size())
        {
            string candidate = msg.substr(pos, len);
            if (m.find(candidate) == m.end())
            {
                break;
            }
            w = candidate;
            ++len;
        }
        answer.push_back(m[w]);
        const int nextPos = pos + static_cast<int>(w.size());
        if (nextPos < msg.size())
        {
            string wc = msg.substr(pos, static_cast<int>(w.size()) + 1);

           // if (dict.find(wc) == dict.end())
            {
                m[wc] = cur_num++;
            }
        }
        pos += w.size();
    }
    return answer;
}