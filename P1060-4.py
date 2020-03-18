
# AC version 2.0
#   one-dimension array version of dynamic programming

class thing:
    def __init__(self):
        self.money = 0
        self.priority = 0


if __name__ == "__main__":
    [n, m] = [int(a) for a in input().split(' ')]

    things = [thing() for a in range(m+1)]

    for i in range(1, m+1):
        [things[i].money, things[i].priority] = [int(a) for a in input().split(' ')]

    maps = [0 for a in range(n+1)]

    for i in range(1, m+1):
        for j in reversed(range(1,n+1)):
            if j >= things[i].money:
                maps[j] = max(maps[j], maps[j-things[i].money] + things[i].money * things[i].priority)

    print(maps[n])
