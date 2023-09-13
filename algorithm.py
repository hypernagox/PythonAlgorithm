import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline
import heapq
dy = [-1,0,1,0]
dx = [0,1,0,-1]
N,M = map(int,input().split())
adj = [list(map(int,input().split())) for _ in range(N)]
island_num = 1
visited = [[False] * M for _ in range(N)]
def numbering(y,x):
    visited[y][x]=True
    adj[y][x] = island_num
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny >= N or nx >= M or ny < 0 or nx < 0:
            continue
        if visited[ny][nx] or adj[ny][nx] == 0:
            continue
        numbering(ny,nx)
for i in range(N):
    for j in range(M):
        if visited[i][j] or 0 == adj[i][j]:
            continue
        numbering(i,j)
        island_num += 1
graph = [[] for _ in range(island_num - 1)]
for i in range(N):
    for j in range(M):
        if adj[i][j] == 0:
            continue
        graph[adj[i][j] - 1].append((i,j))
def makeDari(y,x,start,target,cnt,dir):
    if adj[y][x] == target:
        return cnt
    if adj[y][x] == start or adj[y][x] != 0:
        return sys.maxsize
    ny = y + dy[dir]
    nx = x + dx[dir]
    if ny >= N or nx >= M or ny < 0 or nx < 0:
        return sys.maxsize
    return makeDari(ny,nx,start,target,cnt+1,dir)

adj_graph = [[] for _ in range(island_num - 1)]
for i in range(island_num - 1):
    for j in range(i+1,island_num - 1):
        minval = sys.maxsize
        for y,x in graph[i]:
            for nny,nnx in graph[j]:
                for ii in range(4):
                    ny = y + dy[ii]
                    nx = x + dx[ii]
                    if ny >= N or nx >= M or ny < 0 or nx < 0:
                        continue
                    temp = makeDari(ny, nx,adj[y][x] , adj[nny][nnx], 0,ii)
                    if temp == 1:
                        continue
                    minval = min(minval,temp)
        if minval != sys.maxsize and minval != 1:
            adj_graph[i].append((minval,j))
            adj_graph[j].append((minval,i))
visited2 = [False] * (island_num - 1)
pq = [(0,0)]
bestDist = [sys.maxsize] * (island_num - 1)
bestDist[0] = 0
while pq:
    cost,cur = heapq.heappop(pq)
    if visited2[cur]:
        continue
    visited2[cur] = True
    for w,u in adj_graph[cur]:
        if not visited2[u] and bestDist[u] > w :
            bestDist[u] = w
            heapq.heappush(pq,(w,u))
if all(visited2):
    print(sum(bestDist))
else:
    print(-1)

