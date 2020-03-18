

if __name__ == "__main__":
    [T, M] = [int(a) for a in input().split(' ')]

    times = [0 for a in range(M+1)]
    money = [0 for a in range(M+1)]

    for i in range(1, M+1):
        inputs = [int(a) for a in input().split(' ')]
        times[i] = inputs[0]
        money[i] = inputs[1]

    maps = [0 for a in range(T+1)]

    for i in range(1, M+1):
        for j in reversed(range(1, T+1)):
            if j >= times[i]:
                maps[j] = max(maps[j], maps[j-times[i]] + money[i])

    print(maps[T])