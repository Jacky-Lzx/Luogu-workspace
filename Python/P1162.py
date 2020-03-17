# This is DFS...
def BFS(par):
    if par[0] in range(num) and par[1] in range(num):
        if map[par[0]][par[1]] == 0:
            map[par[0]][par[1]] = -1
            BFS([par[0] + 1, par[1]])
            BFS([par[0] - 1, par[1]])
            BFS([par[0], par[1] + 1])
            BFS([par[0], par[1] - 1])
    return

num = int(input())
map = [0 for i in range(num)]
for i in range(num):
    str = input()
    map[i] = [int(a) for a in str.split(' ')]


for i in range(num):
    if map[0][i] == 0:
        BFS([0, i])
    if map[i][0] == 0:
        BFS([i, 0])
    if map[i][num - 1] == 0:
        BFS([i, num - 1])
    if map[num - 1][i] == 0:
        BFS([num - 1, i])


for i in range(num):
    for j in range(num):
        if map[i][j] == 0:
            map[i][j] = 2
        
        if map[i][j] == -1:
            map[i][j] = 0

for i in range(num):
    for j in range(num - 1):
        print(map[i][j], end = ' ')
    print(map[i][num - 1])