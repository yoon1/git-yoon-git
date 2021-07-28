N,K = map(int, input().split())
nums = [i+1 for i in range (N)]
ret = []
target = 0
for t in range(N):
     target += K-1
     if target >= len(nums) :
         target = target%len(nums)
     ret.append(str(nums.pop(target)))
print("<", ", ".join(ret)[:],">", sep='')