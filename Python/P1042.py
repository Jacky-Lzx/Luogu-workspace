a = 0
b = 0
inputs = []

while True:
    strTemp = input()
    # if strTemp == '':
    #     break
    inputs.append(strTemp)
    if strTemp.find("E") != -1:
        break

for inputline in inputs:
    for i in inputline:
        if i == 'W':
            a += 1
        elif i == 'L':
            b += 1

        if a >= 11 or b >= 11:
            if abs(a - b) >= 2:
                print("%d:%d" % (a, b))
                a = 0
                b = 0

        if i == 'E':
            print("%d:%d" % (a, b))
            a = 0
            b = 0
            print()
            break

# a = 0
# b = 0
for inputLine in inputs:
    for i in inputLine:
        if i == 'W':
            a += 1
        elif i == 'L':
            b += 1

        if a >= 21 or b >= 21:
            if abs(a - b) >= 2:
                print("%d:%d" % (a, b))
                a = 0
                b = 0

        if i == 'E':
            print("%d:%d" % (a, b), end='')
            a = 0
            b = 0
            break
