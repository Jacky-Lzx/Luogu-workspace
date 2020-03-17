# TLE


n = int(input())
array = [int(a) for a in input().split(' ')]
count = 0

for i in range(n):
    for j in range(i+1,n):
        if array[i] > array[j]:
            count += 1

print(count)