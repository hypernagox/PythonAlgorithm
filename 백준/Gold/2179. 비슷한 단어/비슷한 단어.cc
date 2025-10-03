#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <iostream>
#include <sstream>
#include <functional>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <list>
using namespace std;
struct Data
{
	const string str;
	const int cnt;
	const int size;
	const auto operator<(const Data& d)const noexcept {
		if(size ==d.size)
			return cnt < d.cnt;
		return size > d.size;
	}
};
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	unordered_map<char, vector< Data>> m; m.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		string temp; cin >> temp;
		m[temp[0]].emplace_back(temp, i);
	}
	set<pair<Data, Data>> s;
	int cur_val = 0;
	for (const auto& [ch, v] : m)
	{
		if (v.size() == 1)
		{
			continue;
		}
		for (int i = 0; i < v.size(); ++i)
		{
			const auto& [s1, cnt1,si1] = v[i];
			for (int j = i + 1; j < v.size(); ++j)
			{
				int temp = 0;
				const auto& [s2, cnt2,si2] = v[j];
				const auto N = min(s1.size(), s2.size());
				for (int k = 0; k < N; ++k)
				{
					if (s1[k] == s2[k])
					{
						++temp;
					}
					else
					{
						break;
					}
				}
				if (cur_val <= temp)
				{
					cur_val = temp;
					string str1 = s1;
					string str2 = s2;
					int ccnt = min(cnt1, cnt2);
					if (cnt1 > cnt2)
					{
						swap(str1, str2);
					}
					s.emplace(Data{ move(str1),ccnt ,cur_val}, Data{ move(str2),ccnt ,cur_val});
				}
			}
		}
	}
	cout << s.begin()->first.str << '\n';
	cout << s.begin()->second.str << '\n';
}