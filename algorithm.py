import sys
input = sys.stdin.readline
n = int(input())
dists = [[sys.maxsize] * n for _ in range(n)]
for i in range(n):
    cnt = 0
    temp = list(map(int,input().split()))
    for j in temp:
        if 1 == j:
            dists[i][cnt] = 1
        cnt += 1
for k in range(n):
    for u in range(n):
        for v in range(n):
            dists[u][v] = min(dists[u][v],dists[u][k] + dists[k][v])
for lists in dists:
    for i in lists:
        if sys.maxsize == i :
            print(0,end = ' ')
        else:
            print(1,end=' ')
    print()


