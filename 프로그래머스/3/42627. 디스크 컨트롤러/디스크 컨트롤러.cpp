#include <string>
#include <vector>
#include <queue>
using namespace std;
struct Task
{
    int task_num;
    int request_time;
    int require_time;
    Task(int a,int b,int c):task_num{a},request_time{b},require_time{c}{}
    const auto operator<(const Task& task)const {
        if(require_time == task.require_time)
        {
            if(request_time == task.request_time)
            {
                return task_num > task.task_num;
            }
            return request_time > task.request_time;
        }
        return require_time > task.require_time;
    }
    
};
struct CMP
{
    const auto operator()(const Task& a, const Task& b)const{
        return a.request_time > b.request_time;
    }
};
int solution(vector<vector<int>> jobs) 
{
    int answer = 0;
    priority_queue<Task> pq;
    priority_queue<Task,vector<Task>,CMP> arrival;
    for(int i=0;i<jobs.size();++i)
    {
        arrival.emplace(i,jobs[i][0],jobs[i][1]);
    }
    int cur_time = 0;
    while(!arrival.empty() || !pq.empty())
    {
        while(!arrival.empty() && cur_time >= arrival.top().request_time)
        {
            pq.emplace(arrival.top());
            arrival.pop();
        }
        if(pq.empty())
        {
            cur_time = arrival.top().request_time;
           // arrival.pop();
            continue;
        }
        Task t = pq.top(); pq.pop();
        cur_time += t.require_time;
        answer += (cur_time - t.request_time);
    }
    return answer / jobs.size();
}