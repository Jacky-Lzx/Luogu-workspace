
# ! TLE

class thing:
    def __init__(self):
        self.money = 0
        self.priority = 0
    # def money(self):
    #     return self.money
    # def priority(self):
    #     return self.priority

map = {}

def parse(maxMoney, thingsList):
    temp = 0
    for i in thingsList:
        temp += i.money * i.priority
    return temp * maxMoney

def getMax(maxMoney, thingsList):
    if len(thingsList) == 0:
        return 0
    moneys = [0 for a in range(len(thingsList))]
    for i in range(len(thingsList)):
        if maxMoney - thingsList[i].money >= 0:
            if map.get(parse(maxMoney - thingsList[i].money, thingsList[0:i] + thingsList[i+1:])) == None:
                map[parse(maxMoney - thingsList[i].money, thingsList[0:i] + thingsList[i+1:])] = getMax(maxMoney - thingsList[i].money, thingsList[0:i] + thingsList[i+1:])
            moneys[i] = thingsList[i].money * thingsList[i].priority + map[parse(maxMoney - thingsList[i].money, thingsList[0:i] + thingsList[i+1:])]
    return max(moneys)

if __name__ == "__main__":
    [n, m] = [int(a) for a in input().split(' ')]

    things = [thing() for a in range(m)]

    for i in range(m):
        [things[i].money, things[i].priority] = [int(a) for a in input().split(' ')]

    print(getMax(n, things))
