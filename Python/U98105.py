n = int(input())
m = int(input())

array = [0 for a in range(n)]

count = 1

for i in range(m):
    raw = input().split(' ')
    a = int(raw[0])-1
    b = int(raw[1])-1

    if array[a] == 0 and array[b] == 0:
        array[a] = count
        array[b] = count
        count += 1
    elif array[a] != 0 and array[b] == 0:
        array[b] = array[a]
    elif array[a] == 0 and array[b] != 0:
        array[a] = array[b]
    else:
        before = array[b]
        for i in range(n):
            if array[i] == before:
                array[i] = array[a]

        count -= 1

print(count-1)    