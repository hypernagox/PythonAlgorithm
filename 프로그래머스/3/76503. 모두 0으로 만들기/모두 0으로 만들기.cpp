#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector<int> adj[300001];
int deg_[300001];

long long solution(vector<int> a, vector<vector<int>> edges) 
{
    const int n = static_cast<int>(a.size());

    // 전역 자료 초기화 (다중 호출 대비)
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        deg_[i] = 0;
    }

    // 그래프 구성
    for (const auto& e : edges) {
        adj[e[0]].emplace_back(e[1]);
        adj[e[1]].emplace_back(e[0]);
        ++deg_[e[0]];
        ++deg_[e[1]];
    }

    // 전체 합 검사 (불가능 조기 종료)
    long long sum = 0;
    for (int i = 0; i < n; ++i) sum += (long long)a[i];
    if (sum != 0) return -1;

    // 작업용 64비트 배열
    vector<long long> w(n);
    for (int i = 0; i < n; ++i) w[i] = (long long)a[i];

    // 리프부터 시작
    queue<int> q;
    for (int i = 0; i < n; ++i) if (deg_[i] == 1) q.emplace(i);

    long long answer = 0;

    while (!q.empty()) {
        const int cur = q.front();
        q.pop();

        // 리프 cur의 이웃(한 개)을 찾아 처리
        for (int nxt : adj[cur]) {
            if (deg_[nxt] == 0) continue;   // 이미 소거된 정점이면 패스
            // 리프 cur의 값을 전부 nxt로 넘김
            if (w[cur] != 0) {
                answer += llabs(w[cur]);
                w[nxt] += w[cur];
                w[cur] = 0;
            }
            // 간선(cur-nxt) 제거 효과
            --deg_[cur];
            --deg_[nxt];
            if (deg_[nxt] == 1) q.emplace(nxt);
            break; // 리프는 이웃 1개만 처리하면 끝
        }
    }

    // 모두 0이면 성공
    // (sum==0 보장하므로 여기서 추가 검사는 생략 가능하지만, 안전하게 확인하려면 아래 주석을 해제)
    // for (long long x : w) if (x != 0) return -1;

    return answer;
}
