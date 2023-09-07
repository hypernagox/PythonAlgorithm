import sys
input = sys.stdin.readline
import heapq
a,b = map(int,input().split())
graph = [ [] for _ in range(a)]
visited = [False] * a
bestDist = [float("INF")] * a
for _ in range(b):
    u,v,w = map(int,input().split())
    graph[u-1].append((w,v-1))
    graph[v-1].append((w,u-1))
res = 0
pq = []
bestDist[0] = 0
heapq.heappush(pq,(0,0))
while pq:
    dist,cur = heapq.heappop(pq)
    if visited[cur]:
        continue
    visited[cur] = True
    res += dist
    for cost,node in graph[cur]:
        if not visited[node] and bestDist[node] > cost:
            bestDist[node] = cost
            heapq.heappush(pq,(cost,node))
print(res)








