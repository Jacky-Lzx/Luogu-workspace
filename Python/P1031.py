def sun(stacks):
    number = 0
    for i in stacks:
        number += i

    return number


stockNum = int(input())

stacks = input().split(' ')
stacks = [int(e) for e in stacks]

total = sum(stacks)
average = total / stockNum

number = 0
for i in range(stockNum - 1):
    if stacks[i] != average:
        stacks[i + 1] += stacks[i] - average
        number += 1

if stacks[stockNum - 1] != average:
    number += 1

print(number)
