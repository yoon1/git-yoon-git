T = int(input())

# testcase
for i in range(T) :
    a,b = map(int, input().split())
    t = 0
    for j in range(a,b+1) :
        t = t ^ j
    print(t)