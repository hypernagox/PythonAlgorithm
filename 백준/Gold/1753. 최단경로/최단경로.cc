#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
vector<vector<pair<int,int>>> adj;
vector<int> bestDist;
priority_queue<pair<int, int>> pq;
int V, E, a, b,c,d;
template <typename T>
bool chmin(T& a, const T& b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
constexpr int INF = numeric_limits<int>::max();
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E >> a;
	adj.resize(V);
	bestDist.resize(V, INF);
	while (E--) {
		cin >> b >> c >> d;
		adj[b - 1].emplace_back(-d, c - 1);
	}
	bestDist[a - 1] = 0;
	pq.emplace(0,a-1);
	while (!pq.empty()) {
		auto node = pq.top();
		pq.pop();
		if (-node.first > bestDist[node.second])continue;
		for (auto& to : adj[node.second]) {
			if (chmin(bestDist[to.second], -node.first - to.first))
				pq.emplace(-bestDist[to.second], to.second);
		}
	}
	for (auto& dist : bestDist) {
		if (dist == INF)
			cout << "INF";
		else
			cout << dist;
		cout << '\n';
	}
}