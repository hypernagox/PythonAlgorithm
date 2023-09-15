import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000000)
n = int(input())
tree = [[] for _ in range(n)]
temp = list(map(int,input().split()))
root = 0
for i in range(n):
    if -1 == temp[i]:
        root = i
        continue
    tree[temp[i]].append(i)
m = int(input())
cnt = 0
def dfs(cur):
    if m == cur:
       return
    global cnt
    for next in tree[cur]:
        dfs(next)
    if len(tree[cur]) == 0 or (len(tree[cur]) == 1 and tree[cur][0] == m):
        cnt += 1
dfs(root)
print(cnt)

