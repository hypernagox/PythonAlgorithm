#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq{scoville.begin(),scoville.end()};
    while(pq.size() >= 2)
    {
        const auto a = pq.top();pq.pop();
        const auto b = pq.top();
        if(a >= K && b >= K)break;
        pq.pop();
        pq.emplace(a+(b*2));
        ++answer;
    }
    return pq.top() >= K ? answer:-1;
}