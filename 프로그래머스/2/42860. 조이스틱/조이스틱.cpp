#include <string>
#include <vector>
using namespace std;
int solution(string name)
{
    int answer = 0;
    const int n = name.size();
    int m = n - 1;
    for(int i=0;i<n;++i)
    {
        answer += min(name[i]-'A','Z'-name[i] + 1);
        int cursor = i + 1;
        while(cursor < n && name[cursor]=='A')++cursor;
        m = min(m,i + n - cursor + min(i,n-cursor));
    }
    return answer + m;
}