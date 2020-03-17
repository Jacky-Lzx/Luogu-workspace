[N, M] = [int(a) for a in input().split(" ")]

grid = [[] for i in range(N)]
for i in range(N):
    grid[i] = [int(a) for a in input().split(' ')]

raw = input().split(' ')
start = [int(a) for a in raw[0:2]]
end = [int(a) for a in raw[2:4]]
direction = raw[4]

map = [[] for _ in range(N - 1)]
for i in range(N - 1):
    map[i] = [0 for _ in range(M - 1)]

for i in range(len(grid)):
    for j in range(len(grid[i])):
        if grid[i][j] == 1:
            if i >= 1:
                if j < M - 1:
                    map[i - 1][j] = 1
                if j >= 1:
                    map[i - 1][j -1] = 1
            if i < N - 1:
                if j < M - 1:
                    map[i][j] = 1
                if j >= 1:
                    map[i][j - 1] = 1


steps = [[] for _ in range(N - 1)]
for i in range(N - 1):
    steps[i] = [0 for _ in range(M - 1)]

