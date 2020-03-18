
# AC
# * Notes: the index of j ends in 0
# * even lose the game also get exp
n, x = map(int, input().split())

lose = [0] * (n+1)
win = [0] * (n+1)
use = [0] * (n+1)

for i in range(1, n+1):
    lose[i], win[i], use[i] = map(int, input().split())

maps = [0] * (x+1)

for i in range(1, n+1):
    for j in reversed(range(0, x+1)):
        if j >= use[i]:
            maps[j] = max(maps[j] + lose[i], maps[j-use[i]]+win[i])
        else:
            maps[j] = maps[j] + lose[i]

print(maps[x]*5)