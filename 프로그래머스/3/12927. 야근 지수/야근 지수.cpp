#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
long long solution(int n, vector<int> works)
{
	priority_queue<int> pq{ works.begin(),works.end() };
	ll sum = 0;
	while (n--)
	{
		const auto val = pq.top();
		pq.pop();
		pq.emplace(max(0, val - 1));
	}
	while (!pq.empty())
	{
		sum += pq.top() * pq.top();
		pq.pop();
	}
	return sum;
}