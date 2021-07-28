l1 = []
for i in range(4):
    t = int(input())
    l1.append(t)
l2 = []
for i in range(2):
    t = int(input())
    l2.append(t)
l1.sort(reverse=True)
l2.sort(reverse=True)

print(sum(l1[0:3]) + l2[0])