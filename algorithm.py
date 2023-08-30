import sys
input = sys.stdin.readline
n,m = map(int,input().split())
class DisjointSet:
    def __init__(self,n):
        self.parent=[i for i in range(n)]
        self.rank = [0 for _ in range(n)]
    def Find(self,n):
        if self.parent[n] == n:
            return n
        self.parent[n] = self.Find(self.parent[n])
        return self.parent[n]
    def Union(self,u,v):
        if u == v:
            return False
        u = self.Find(u)
        v = self.Find(v)
        if u == v :
            return False
        if(self.rank[u] > self.rank[v]):
            u,v = v,u
        self.parent[u] = v
        if(self.rank[u] == self.rank[v]):
            self.rank[v] +=1
        return True
adj = []
for _ in range(m):
    u,v,w = map(int,input().split())
    adj.append((u - 1,v - 1,w))
adj.sort(key = lambda x:x[2])
uf = DisjointSet(n)
res = 0
for u,v,w in adj:
    if uf.Union(u,v):
        res +=w
print(res)








