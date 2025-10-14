#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
bool visited[10];
ull min_diff = ULLONG_MAX;
ull res = 0;
void GO(const string& num, string& str)
{
	if(!str.empty())
	{
		auto s1 = stoull(num);
		auto s2 = stoull(str);
		//if (s1 > s2)swap(s1, s2);
		const auto diff = llabs(s2 - s1);
		if (diff <= min_diff)
		{
			if (diff == min_diff)
			{
				res = min(res, s2);
			}
			else
			{
				res = s2;
			}
			min_diff = diff;
		}
		//return;
	}
	for (int i = 0; i <= 9; ++i)
	{
		if (visited[i])continue;
		if (i == 0 && str.empty())continue;
		visited[i] = true;
		str.push_back(i + '0');
		GO(num, str);
		str.pop_back();
		visited[i] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string num; cin >> num;
	string str;
	GO(num, str);
	cout << res;
}