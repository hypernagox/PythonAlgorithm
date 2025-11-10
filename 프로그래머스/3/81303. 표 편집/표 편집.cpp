#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_set>
using namespace std;
struct Node
{
    int val = -1;
    Node* prev=nullptr;
    Node* next= nullptr;
};
Node* pool;
string solution(int n, int k, vector<string> cmd) 
{
    pool = new Node[n];
    string answer = "";
    Node head;
    Node* cur = &head;
    Node* cursor=nullptr;
    vector<Node*> stack;
    unordered_set<int> dlist;
    dlist.reserve(n);
    stack.reserve(n);
    answer.reserve(n);
    int cnt=0;
    for(int i=0;i<n;++i)
    {
        auto temp = &pool[cnt++];
        temp->val=i;
        if(i == k)cursor=temp;
        cur->next=temp;
        temp->prev=cur;
        cur=temp;
    }
    for(auto& c: cmd)
    {
        //stringstream sstream{move(c)};
        
        char ch; int x;
        ch=c[0];
        //sstream>>ch;
        if(ch =='U')
        {
          //  sstream>>x;
            x=stoi(c.substr(2));
            while(x--)
            {
                cursor = cursor->prev;
            }
        }
        else if(ch =='D')
        {
           // sstream>>x;
            x=stoi(c.substr(2));
            while(x--)
            {
                cursor = cursor->next;
            }
        }
        else if(ch =='C')
        {
            const auto prev = cursor->prev;
            const auto next = cursor->next;
            prev->next=next;
            if(next)next->prev=prev;
            dlist.emplace(cursor->val);
            stack.emplace_back(cursor);
            if(next)cursor=next;
            else cursor=prev;
        }
        else
        {
            const auto target = stack.back();
            stack.pop_back();
            dlist.erase(target->val);
            target->prev->next =target;
            if(target->next)target->next->prev=target;
            
        }
    }
    //sort(istack.begin(),istack.end());
    for(int i=0;i<n;++i)
    {
        if(dlist.count(i))
        {
             answer.push_back('X');
        }
        else
        {
            answer.push_back('O');
        }
    }
    return answer;
}