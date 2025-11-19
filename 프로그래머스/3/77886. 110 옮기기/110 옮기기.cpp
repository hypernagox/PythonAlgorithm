#include <string>
#include <vector>
using namespace std;

vector<string> solution(vector<string> ss)
{
    vector<string> answer;
   for(const auto& s:ss)
   {
       string target="";
       string ooz="";
       for(int i=0;i< s.size();++i)
       {
           target.push_back(s[i]);
           if(target.size() >= 3)
           {
               if(target.substr(target.size()-3) == "110")
               {
                   ooz+="110";
                   int t=3;
                   while(t--)target.pop_back();
               }
           }
       }
       int last_zero = -1;
       for(int i=target.size()-1;i>=0;--i)
       {
           if(target[i]=='0')
           {
               last_zero=i;
               break;
           }
       }
       if(-1 == last_zero)
       {
           target = ooz + target;
       }
       else
       {
           target.insert(last_zero + 1,ooz);
       }
       answer.emplace_back(move(target));
   }
    return answer;
}
