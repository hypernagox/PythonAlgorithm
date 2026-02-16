#include <bits/stdc++.h>
using namespace std;

constexpr int dy[4]{-1,0,1,0};
constexpr int dx[4]{0,1,0,-1};
constexpr int INF = 987654321;

vector<vector<int>> m;
bool visited[5][5][2]; // 0: red, 1: blue
int r_dest_y, r_dest_x, b_dest_y, b_dest_x;
int ans = INF;

bool CanGo(int y, int x) {
    if (y < 0 || x < 0 || y >= (int)m.size() || x >= (int)m[0].size()) return false;
    if (m[y][x] == 5) return false; // wall
    return true;
}

void GO(int ry, int rx, int by, int bx, int cnt) {
    if (cnt >= ans) return;

    bool redDone  = (ry == r_dest_y && rx == r_dest_x);
    bool blueDone = (by == b_dest_y && bx == b_dest_x);

    if (redDone && blueDone) {
        ans = min(ans, cnt);
        return;
    }

    // 다음 후보 위치 만들기: 도착했으면 제자리만 후보
    vector<pair<int,int>> Rnext, Bnext;

    if (redDone) {
        Rnext.push_back({ry, rx});
    } else {
        for (int dir = 0; dir < 4; ++dir) {
            int ny = ry + dy[dir];
            int nx = rx + dx[dir];
            if (!CanGo(ny, nx)) continue;
            if (visited[ny][nx][0]) continue;
            Rnext.push_back({ny, nx});
        }
    }

    if (blueDone) {
        Bnext.push_back({by, bx});
    } else {
        for (int dir = 0; dir < 4; ++dir) {
            int ny = by + dy[dir];
            int nx = bx + dx[dir];
            if (!CanGo(ny, nx)) continue;
            if (visited[ny][nx][1]) continue;
            Bnext.push_back({ny, nx});
        }
    }

    // 이동 불가면 종료
    if (Rnext.empty() || Bnext.empty()) return;

    for (auto [nry, nrx] : Rnext) {
        for (auto [nby, nbx] : Bnext) {
            // 같은 칸 도착 금지
            if (nry == nby && nrx == nbx) continue;

            // 서로 자리 바꾸기(swap) 금지: (R이 B의 현재로) && (B가 R의 현재로)
            if (nry == by && nrx == bx && nby == ry && nbx == rx) continue;

            // “상대의 현재 칸으로 들어가기 금지”가 규칙인 경우도 많아서(동시 이동이라도),
            // 이미 위 swap 체크로 대부분 커버되지만, 원하면 아래도 유지 가능.
            // if (!redDone  && nry == by && nrx == bx) continue;
            // if (!blueDone && nby == ry && nbx == rx) continue;

            bool markR = false, markB = false;

            if (!(redDone) ) { // 빨강이 이동한 경우만 방문 체크
                visited[nry][nrx][0] = true;
                markR = true;
            }
            if (!(blueDone)) { // 파랑이 이동한 경우만 방문 체크
                visited[nby][nbx][1] = true;
                markB = true;
            }

            GO(nry, nrx, nby, nbx, cnt + 1);

            if (markR) visited[nry][nrx][0] = false;
            if (markB) visited[nby][nbx][1] = false;
        }
    }
}

int solution(vector<vector<int>> maze) {
    m = std::move(maze);
    ans = INF;
    memset(visited, 0, sizeof(visited));

    int ry=-1, rx=-1, by=-1, bx=-1;

    for (int i = 0; i < (int)m.size(); ++i) {
        for (int j = 0; j < (int)m[0].size(); ++j) {
            if (m[i][j] == 1) { ry = i; rx = j; visited[i][j][0] = true; }
            else if (m[i][j] == 2) { by = i; bx = j; visited[i][j][1] = true; }
            else if (m[i][j] == 3) { r_dest_y = i; r_dest_x = j; }
            else if (m[i][j] == 4) { b_dest_y = i; b_dest_x = j; }
        }
    }

    GO(ry, rx, by, bx, 0);
    return (ans >= INF) ? 0 : ans;
}
