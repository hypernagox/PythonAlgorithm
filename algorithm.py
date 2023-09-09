import sys
input = sys.stdin.readline
import heapq
a = int(input())
b = int(input())
adj = [[] for _ in range(a)]
bestDist = [float("INF")] * a
for _ in range(b):
    u,v,w = map(int,input().split())
    adj[u-1].append((w,v-1))
start,end = map(int,input().split())
pq = []
bestDist[start-1]=0
heapq.heappush(pq,(0,start-1))
while pq:
    cost,cur = heapq.heappop(pq)
    if bestDist[cur] < cost:
        continue
    for nextCost,node in adj[cur]:
        if bestDist[node] > cost + nextCost:
            bestDist[node] = cost + nextCost
            heapq.heappush(pq,(bestDist[node],node))
print(bestDist[end-1])



