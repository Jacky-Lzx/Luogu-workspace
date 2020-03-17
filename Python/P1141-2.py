posX = [0, 0, -1, 1]
posY = [1, -1, 0, 0]
def DFS(pos):
    num = map[pos[0]][pos[1]]
    for i in range(4):
        newPos = [pos[0] + posX[i], pos[1] + posY[i]]
        if newPos[0] in range(n) and newPos[1] in range(n):
            if flag[newPos[0]][newPos[1]] == 0 and map[newPos[0]][newPos[1]] != num:
                flag[newPos[0]][newPos[1]] = 1
                count[0] += 1
                DFS(newPos)


_ = input().split(' ')
n = int(_[0])
m = int(_[1])

map = [[0 for _ in range(n)] for i in range(n)]
for i in range(n):
    str = input()
    for j in range(n):
        map[i][j] = int(str[j])
        

countMap = [[-1 for _ in range(n)] for i in range(n)]
for _ in range(m):
    posOriginal = [int(a) - 1 for a in input().split(' ')]

    if countMap[posOriginal[0]][posOriginal[1]] != -1:
        print(countMap[posOriginal[0]][posOriginal[1]])
        continue


    count = [1]
    flag = [[0 for _ in range(n)] for i in range(n)]
    flag[posOriginal[0]][posOriginal[1]] = 1
    DFS(posOriginal)

    for indexi in range(n):
        for indexj in range(n):
            if flag[indexi][indexj] != 0:
                countMap[indexi][indexj] = count[0]

    print(count[0])
