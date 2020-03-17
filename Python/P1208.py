[sumsMilk, b] = [int(e) for e in input().split(' ')]
inputs1 = []
inputs2 = []
sumMoney = 0

for i in range(b):
    [temp1, temp2] = input().split(' ')
    inputs1.append(int(temp1))
    inputs2.append(int(temp2))

while sumsMilk > 0:
    min = 0
    for i in range(len(inputs1)):
        if inputs1[min] >= inputs1[i]:
            min = i

    if sumsMilk <= inputs2[min]:
        sumMoney += inputs1[min] * sumsMilk
        break

    sumMoney += inputs1[min] * inputs2[min]
    sumsMilk -= inputs2[min]
    del inputs1[min], inputs2[min]


print(sumMoney)
