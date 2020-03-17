def construct(num):
    count = -1
    string = ''
    while num != 0:
        count += 1
        if num & 1 == 1:
            if count >= 3:
                newStr = construct(count)
                string = '2(' + newStr[0:-1] + ')' + '+' + string
            elif count == 1:
                string = '2+' + string
            else:
                string = '2(' + str(count) + ')' + '+' + string
        # print(n & 1)
        num = num >> 1
    return string




if __name__ == "__main__":
    n = int(input())

    string = construct(n)
    
    # string[len(string)]
    print(string[0:-1])


