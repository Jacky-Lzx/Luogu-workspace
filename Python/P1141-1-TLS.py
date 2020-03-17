posX = [0, 0, -1, 1]
posY = [1, -1, 0, 0]


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


    count = 1
    queue = [posOriginal]
    flag = [[0 for _ in range(n)] for i in range(n)]
    while len(queue) != 0:
        pos = queue.pop(0)
        flag[pos[0]][pos[1]] = 1
        num = map[pos[0]][pos[1]]
        for i in range(4):
            newpos = [pos[0] + posX[i], pos[1] + posY[i]]
            if newpos[0] in range(n) and newpos[1] in range(n) and num != map[newpos[0]][newpos[1]]:
                if flag[newpos[0]][newpos[1]] == 0:
                    count = count + 1
                    flag[newpos[0]][newpos[1]] = 1
                    queue.append(newpos)


    for indexi in range(n):
        for indexj in range(n):
            if flag[indexi][indexj] != 0:
                countMap[indexi][indexj] = count

    print(count)
