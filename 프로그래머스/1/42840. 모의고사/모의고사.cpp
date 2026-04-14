#include <bits/stdc++.h>
using namespace std;
constexpr const int p1[]{1, 2, 3, 4, 5};
constexpr const int p2[]{2, 1, 2, 3, 2, 4, 2, 5};
constexpr const int p3[]{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int num_ans[3];
vector<int> solution(vector<int> answers) 
{
    vector<int> answer;
    int j=-1;
    for(int i=0;i<answers.size();++i)
    {
        num_ans[0] += answers[i] == p1[(j+1) % (sizeof(p1)/sizeof(int))];
        num_ans[1] += answers[i] == p2[(j+1) % (sizeof(p2)/sizeof(int))];
        num_ans[2] += answers[i] == p3[(j+1) % (sizeof(p3)/sizeof(int))];
        ++j;
    }
    int max_score=-1;
    for(int i=0;i<3;++i)
    {
        max_score=max(max_score,num_ans[i]);
    }
    for(int i=0;i<3;++i)
    {
        if(max_score == num_ans[i])answer.emplace_back(i+1);
    }
    return answer;
}