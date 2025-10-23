#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
vector<string> comb;
int max_idx;
void GO(const int cur_idx = 0,string cur = "")
{
	for (int i = cur_idx; i < max_idx; ++i)
	{
		cur.push_back(i + '0');
		comb.emplace_back(cur);
		GO(i + 1, cur);
		cur.pop_back();
	}
}
int solution(vector<vector<string>> relation) 
{
	max_idx = relation.front().size();
	GO();
	sort(comb.begin(), comb.end(), [](auto& a, auto& b) {
		if (a.size() == b.size())return a < b;
		return a.size() < b.size();
		});
	vector<string> key_list;
	for (const auto& c : comb)
	{
		set<string> s;
		bool flag = true;
		for (int i = 0; i < relation.size(); ++i)
		{
			string temp;
			for (int j = 0; j < c.size(); ++j)
			{
				temp += relation[i][c[j] - '0'];
			}
			if (!s.emplace(temp).second)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			for (const auto& list : key_list)
			{
				if (includes(c.begin(), c.end(),list.begin(), list.end()))
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				key_list.emplace_back(c);
			}
		}
	}
	//for (const auto& i : key_list)cout << i << endl;
	return key_list.size();
}