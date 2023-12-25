import sys

N, K = map(int, sys.stdin.readline().split())
lst = [i for i in range(1, N+1)]
anw = []
t = K-1
for i in range(1, N + 1):
    anw.append(lst[t])
    del lst[t]
    if len(lst) == 0:
        break
    else:
        t = ((t-1)+K)%len(lst)
print('<', end="")
print(*anw, sep=', ', end="")
print('>', end="")