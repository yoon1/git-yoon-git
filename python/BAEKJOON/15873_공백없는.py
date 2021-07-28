a = input();
if a[0] == '1' :
    if a[1] == '0' :
        print(10 + int(a[2:]))
    else :
        print(1 + int(a[1:]))
else :
    print(int(a[0]) + int(a[1:]))