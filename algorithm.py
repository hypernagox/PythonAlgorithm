import sys
import heapq
input = sys.stdin.readline
n,m = map(int,input().split())
start = int(input().strip())
adj = [[] for _ in range(n)]
bestDist = [float("inf")] * n
q = []
for _ in range(m):
    a,b,c = map(int,input().split())
    adj[a-1].append((c,b-1))
bestDist[start - 1] = 0
heapq.heappush(q,(0,start - 1))
while q:
    cost,node = heapq.heappop(q)
    if bestDist[node] < cost:
        continue
    for next in adj[node]:
        nextCost = next[0] + cost
        if(bestDist[next[1]] > nextCost):
            bestDist[next[1]] = nextCost
            heapq.heappush(q,(nextCost,next[1]))
for i in bestDist:
    if float("inf") == i:
        print("INF")
    else:
        print(i)









