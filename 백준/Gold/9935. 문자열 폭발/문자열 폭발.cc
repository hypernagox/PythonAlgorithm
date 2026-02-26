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
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str, target;
	cin >> str >> target;
	string stack; stack.reserve(str.size());
	for (int i = 0; i < str.size(); ++i)
	{
		stack.push_back(str[i]);
		if (stack.size() < target.size())
		{
			continue;
		}
		const auto b = stack.size() - target.size();
		string_view sub{ stack.data() + b,stack.data() + b + target.size() };
		if (sub == target)
		{
			int n = (int)target.size();
			while (n--)
			{
				stack.pop_back();
			}
		}
	}
	if (stack.empty())
	{
		cout << "FRULA";
	}
	else
	{
		cout << stack;
	}
}