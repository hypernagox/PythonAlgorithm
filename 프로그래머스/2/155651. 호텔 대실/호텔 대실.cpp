#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <cstring>
using namespace std;
int TimeToInt(const string& str)
{
	const auto h = str.substr(0, 2);
	const auto m = str.substr(3, 2);
	return stoi(h) * 60 + stoi(m);
}
int solution(vector<vector<string>> book_time) 
{
	int answer = 0;
	vector<pair<int, int>> times;
	for (const auto& v : book_time)
	{
		const auto s = TimeToInt(v[0]);
		const auto e = TimeToInt(v[1]);
		times.emplace_back(s, e);
	}
	sort(times.begin(), times.end());
	priority_queue<int> pq;
	for (int i = 0; i < times.size(); ++i)
	{
		if (pq.empty() || -pq.top() > times[i].first)
		{
			++answer;
		}
		else
		{
			pq.pop();
		}
		pq.emplace(-(times[i].second + 10));
	}
	return answer;
}