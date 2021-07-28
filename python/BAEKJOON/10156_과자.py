K, N, M = map(int, input().split())
print(0 if K * N < M else K * N - M)