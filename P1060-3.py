
# AC version 1.0
#   Initial version of dynamic programming

class thing:
    def __init__(self):
        self.money = 0
        self.priority = 0


if __name__ == "__main__":
    [n, m] = [int(a) for a in input().split(' ')]

    things = [thing() for a in range(m+1)]

    for i in range(1, m+1):
        [things[i].money, things[i].priority] = [int(a) for a in input().split(' ')]

    maps = [[0 for a in range(n+1)] for b in range(m+1)]

    for i in range(1, m+1):
        for j in range(1,n+1):
            if j < things[i].money:
                maps[i][j] = maps[i-1][j]
            else:
                maps[i][j] = max(maps[i-1][j], maps[i-1][j-things[i].money] + things[i].money * things[i].priority)

    print(maps[m][n])

# master test