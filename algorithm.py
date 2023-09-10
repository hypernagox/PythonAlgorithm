import heapq
import sys
input = sys.stdin.readline
n,m,k = map(int,input().split())
adj = [[] for _ in range(n)]
for _ in range(m):
    u,v,w = map(int,input().split())
    adj[u-1].append((w,v-1))
pq = []
citys = [[] for _ in range(n)]
heapq.heappush(pq,(0,0))
citys[0].append(0)
while pq:
    dist,cur = heapq.heappop(pq)
    for cost,next in adj[cur]:
        nextDist = cost + dist
        if len(citys[next]) < k :
            heapq.heappush(pq,(nextDist,next))
            heapq.heappush(citys[next],-nextDist)
        elif citys[next][0] < -nextDist :
            heapq.heappop(citys[next])
            heapq.heappush(citys[next],-nextDist)
            heapq.heappush(pq,(nextDist,next))
for i in range(n):
    if len(citys[i]) == k:
        print(-citys[i][0])
    else:
        print(-1)
