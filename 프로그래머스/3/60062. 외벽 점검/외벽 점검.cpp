#include <bits/stdc++.h>
using namespace std;
int solution(int n, vector<int> weak, vector<int> dist) 
{
    int answer = 987654321;
    sort(dist.begin(),dist.end());
    const auto N = (int)weak.size();
    for(int i=0;i<N;++i)
    {
        weak.emplace_back(weak[i]+n);
    }
    do
    {
        for(int i=0;i<N;++i)
        {
            int start = weak[i];
            const int end = weak[i + N - 1];
            for(int j=0;j<dist.size();++j)
            {
                start += dist[j];
                if(start >= end)
                {
                    answer =min(answer,j+1);
                    break;
                }
                for(int k=i+1;k<weak.size();++k)
                {
                    if(start < weak[k])
                    {
                        start=weak[k];
                        break;
                    }
                }
            }
        }
    }while(next_permutation(dist.begin(),dist.end()));
    return answer == 987654321 ? -1 : answer;
}