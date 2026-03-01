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
int arr[100001];
int table[100001];
int n;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int b = 0;
	int e = 0;
	while (e < n)
	{
		const auto val = arr[e];
		++table[val];
		while (table[val] > 1)
		{
			--table[arr[b]];
			++b;
		}
		ans += (e - b) + 1;
		++e;
	}
	cout << ans;
}