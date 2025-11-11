#include <string>
#include <vector>
#include <queue>
using namespace std;
struct Task
{
    int task_num;
    int start_time;
    int need_time;
    Task(int a,int b,int c):task_num{a},start_time{b},need_time{c}{}
};
struct CMP1
{
    const auto operator()(const Task& a,const Task& b)const{
        if(a.need_time == b.need_time)
        {
            if(a.start_time == b.start_time)
            {
                return a.task_num > b.task_num;
            }
            return a.start_time > b.start_time;
        }
        return a.need_time > b.need_time;
    }
};
struct CMP2
{
    const auto operator()(const Task& a,const Task& b)const{
        return a.start_time > b.start_time;
    }
};
int solution(vector<vector<int>> jobs) 
{
    int answer = 0;
    priority_queue<Task,vector<Task>,CMP1> pq;
     priority_queue<Task,vector<Task>,CMP2> arrived_task;
    for(int i=0;i<jobs.size();++i)
    {
        arrived_task.emplace(i,jobs[i][0],jobs[i][1]);
    }
    int cur_time = 0;
    while(!arrived_task.empty() || !pq.empty())
    {
        while(!arrived_task.empty() && cur_time >= arrived_task.top().start_time)
        {
            pq.emplace(arrived_task.top());arrived_task.pop();
        }
        // 타임라인상 더 할일이 없다면 다음 일 할 시간으로 점프
        if(pq.empty())
        {
            cur_time = arrived_task.top().start_time;
            continue;
        }
       //while(!pq.empty())
       {
           const auto task = pq.top();pq.pop();
         //  cur_time += task.need_time;
           answer += max(cur_time - task.start_time,0);
           answer += task.need_time;
          cur_time += task.need_time;
       }
    }
    return answer / jobs.size();
}