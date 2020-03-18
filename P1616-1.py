
# ! TLE

if __name__ == "__main__":
    [T, M] = [int(a) for a in input().split(' ')]

    originTimes = [0 for a in range(M+1)]
    originMoney = [0 for a in range(M+1)]

    for i in range(1,M+1):
        inputs = [int(a) for a in input().split(' ')]
        originTimes[i] = inputs[0]
        originMoney[i] = inputs[1]
    
    sum = 0
    for i in range(1, M+1):
        sum += int(T / originTimes[i])

    times = [0 for i in range(sum+1)]
    money = [0 for i in range(sum+1)]

    index = 1
    for i in range(1, M+1):
        n = int(T/originTimes[i])
        for j in range(n):
            times[index + j] = originTimes[i]
            money[index + j] = originMoney[i]

    
    maps = [0 for a in range(T+1)]

    for a in range(1, sum+1):
        for b in reversed(range(1, T+1)):
            if b >= times[i]:
                maps[b] = max(maps[b], maps[b-times[i]] + money[i])

    print(maps[T])