#include <bits/stdc++.h>
using namespace std;

int n, m, c;
int board[55][55];
const int dy[]{ 1, 0 };
const int dx[]{ 0, 1 };
static constexpr long long MOD = 1000007;

// 0개부터 50개까지의 경우의 수를 담을 구조체
struct Node {
    long long counts[52];

    Node() {
        memset(counts, 0, sizeof(counts));
    }

    // 두 결과(경로)를 합치는 연산자 오버로딩
    Node operator+(const Node& other) const {
        Node ret;
        for (int i = 0; i <= c; ++i) {
            ret.counts[i] = (counts[i] + other.counts[i]) % MOD;
        }
        return ret;
    }
};

// dp[y][x][last_val]: (y, x)에 도착했고, 직전에 주운 값이 last_val일 때
// 앞으로 (N, M)까지 가면서 얻을 수 있는 추가적인 물건 개수별 경우의 수들
Node dp[51][51][51];
bool visited[51][51][51]; // 메모이제이션 여부 확인

Node GO(int y, int x, int last_val) {
    // 1. 범위 체크
    if (y > n || x > m) return Node();

    // 2. 현재 위치 처리 (진입 조건 확인)
    int current_val = board[y][x];
    int added_cnt = 0;
    int next_last = last_val;

    if (current_val > 0) {
        // 물건이 있는데 이전 물건보다 작거나 같으면 이 칸은 밟을 수 없음 (경로 소멸)
        if (current_val <= last_val) return Node();
        
        // 밟을 수 있다면 상태 업데이트
        added_cnt = 1;
        next_last = current_val;
    }

    // 3. 기저 사례: 도착점
    if (y == n && x == m) {
        Node base;
        // 도착점에 무사히 안착했다면, 현재 칸에서 추가된 개수(0 or 1) 위치에 1을 기록
        base.counts[added_cnt] = 1; 
        return base;
    }

    // 4. 메모이제이션 확인
    if (visited[y][x][last_val]) {
        return dp[y][x][last_val];
    }

    // 5. 재귀 호출 (하, 우)
    Node result; // 0으로 초기화된 상태
    for (int i = 0; i < 2; ++i) {
        // 다음 칸으로 이동할 때는 갱신된 next_last를 들고 감
        result = result + GO(y + dy[i], x + dx[i], next_last);
    }

    // 6. 현재 칸의 영향 반영 (Shift)
    // 만약 현재 칸에서 물건을 주웠다면(added_cnt == 1),
    // 자식 노드들에서 가져온 결과들의 개수를 모두 +1 해줘야 함.
    // (예: 자식노드에서 2개 주워온 경우 -> 현재 포함 총 3개가 됨)
    Node final_ret;
    if (added_cnt == 1) {
        for (int i = 0; i < c; ++i) {
            final_ret.counts[i + 1] = result.counts[i];
        }
    } else {
        final_ret = result;
    }

    visited[y][x][last_val] = true;
    return dp[y][x][last_val] = final_ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> c;
    for (int i = 0; i < c; ++i) {
        int a, b; cin >> a >> b;
        board[a][b] = i + 1;
    }

    // (1, 1)에서 시작, 초기 last_val은 0
    Node ans = GO(1, 1, 0);

    // 결과 출력
    for (int i = 0; i <= c; ++i) {
        cout << ans.counts[i] << ' ';
    }

    return 0;
}