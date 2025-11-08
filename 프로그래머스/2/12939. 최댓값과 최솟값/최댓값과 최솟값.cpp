#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s)
{
   vector<int> v;
    stringstream sstream{s};
    int x;
    while(sstream >> x)
    {
        v.emplace_back(x);
    }
    sort(v.begin(),v.end());
    return to_string(v.front())+" "+to_string(v.back());
}