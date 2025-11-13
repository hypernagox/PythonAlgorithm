#include <string>
#include <vector>
#include <sstream>
using namespace std;

string solution(string s) 
{
    string answer = "";
    string str;
    stringstream sstream{s};
    string target;
    while(sstream>>str)
    {
        if(isalpha(str[0]))
        {
            str[0]=toupper(str[0]);
        }
        for(int i=1;i<str.size();++i)
        {
            if(isalpha(str[i]))
            {
            str[i]=tolower(str[i]);
            }
        }
        target+=str;
    }
    int j = 0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]==' ')
        {
            answer.push_back(' ');
        }
        else
        {
            answer.push_back(target[j++]);
        }
    }
    return answer;
}