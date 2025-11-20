#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int String2Int(const string& time)
{
    const auto h = time.substr(0,2);
    const auto m = time.substr(3,2);
    return stoi(h)*60+stoi(m);
}
struct Data
{
  int play_time;
    int start_time;
    string name;
    const auto operator<(const Data& d)const{
        if(play_time == d.play_time)
        {
            return start_time < d.start_time;
        }
        return play_time > d.play_time;
    }
    Data(int a,int b,string n):play_time{a},start_time{b},name{n}{}
};
string solution(string m, vector<string> musicinfos) 
{
    string answer = "(None)";
    int max_time = -1;
    int start_time = 987654321;
    vector<Data> v;
    for(const auto& d:musicinfos)
    {
        int cur = 0;
        string data[4];
        for(const auto ch: d)
        {
            if(ch == ',')
            {
                ++cur;
                continue;
            }
            data[cur].push_back(ch);
        }
        string music_book;
        int cur_time = 0;
        const auto end = String2Int(data[1]);
        const auto start = String2Int(data[0]);
        const auto play_time = end - start;
        int pos = 0;
        while(cur_time < play_time)
        {
            const auto m = data[3][pos];
            if(m =='#')continue;
            music_book.push_back(m);
            if(pos < data[3].size() - 1 && '#' == data[3][pos+1])
            {
                music_book.push_back('#');
                pos = (pos + 1) % data[3].size();
            }
            pos = (pos + 1) % data[3].size();
            ++cur_time;
        }
        bool flag = false;
        if(m.size() > music_book.size())continue;
        for(int i=0;i<= music_book.size()-m.size();++i)
        {
            const auto j = i + m.size();
            if(j < music_book.size() && music_book[j]=='#')
            {
                continue;
            }
            if(m == music_book.substr(i,m.size()))
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            v.emplace_back(play_time,start,data[2]);
        }
        //cout<<music_book<<endl;
        
    }
    sort(v.begin(),v.end());
    if(v.empty())return "(None)";
    else return v.front().name;
    return answer;
}