import heapq

hq = []
a,b = map(int, input().split())
for i in range(2) :
    t = map(int, input().split())
    for e in t :
        heapq.heappush(hq, e)
while hq :
    print(heapq.heappop(hq), end=' ')

