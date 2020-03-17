length = int(input())

numbers = input().split(' ')
numbers.sort().reverse()

for i in range(length - 1):
    if (numbers[i] + numbers[i + 1]) < (numbers[i + 1] + numbers[i]):
        temp = numbers[i + 1]
        numbers[i + 1] = numbers[i]
        numbers[i] = temp

for stri in numbers:
    print(int(stri), end="")

print()
