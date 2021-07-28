i = 1
j = 2
num = 3

while i <= 10 :
    while j <= num:
        if num% j == 0:
            break
        j = j + 1
    if num == j:
        print("%d번째 소수는 %d\n", i, num)
        i = i + 1
    num = num + 1
