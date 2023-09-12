import sys
input = sys.stdin.readline
import heapq
n = int(input())
adj = [[] for _ in range(n)]
visited = [False] * n
bestCost = [sys.maxsize] * n
sum = 0
for i in range(n):
    temp = str(input().strip())
    j = 0
    for ch in temp:
        x = 0
        if '0' == ch:
            x = 0
        elif ch.islower():
            x = ord(ch) - ord('a') + 1
        else:
            x = ord(ch) - ord('A') + 27
        if i != j and 0 != x:
            adj[i].append((x,j))
            adj[j].append((x,i))
        sum += x
        j += 1
pq = []
bestCost[0] = 0
res = 0
heapq.heappush(pq,(0,0))
while pq:
    cost,cur = heapq.heappop(pq)
    if visited[cur]:
        continue
    visited[cur] = True
    res += cost
    for dist,next in adj[cur]:
        if not visited[next] and bestCost[next] > dist:
            bestCost[next] = dist
            heapq.heappush(pq,(dist,next))
if all(visited):
    print(sum - res)
else:
    print(-1)



