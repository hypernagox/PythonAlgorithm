#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> tree[100001];
bool visited[100001];
int num[100001];
int a, b, c;
void go(int curNode)
{
	visited[curNode] = 1;
	num[curNode] = 1;
	for (const auto i : tree[curNode]) {
		if (visited[i])continue;
		go(i);
		num[curNode] += num[i];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b >> c;
	a--;
	while (a--) {
		int x, y; cin >> x >> y;
		tree[x].emplace_back(y);
		tree[y].emplace_back(x);
	}
	go(b);
	while (c--) {
		int x; cin >> x;
		cout << num[x] << '\n';
	}
}