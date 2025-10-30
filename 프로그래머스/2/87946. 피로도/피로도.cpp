#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool visited[10];
int res = 0;
int GO(const vector<vector<int>>& dungeons, const int K, const int cnt = 0)
{
    for(int i=0;i<dungeons.size();++i)
    {
        if(visited[i])continue;
        if(K < dungeons[i][0])continue;
        visited[i]=true;
        GO(dungeons,K - dungeons[i][1], cnt + 1);
        visited[i]=false;
    }
    return res = max(res,cnt);
}
int solution(int k, vector<vector<int>> dungeons) 
{
    return GO(dungeons,k);
}