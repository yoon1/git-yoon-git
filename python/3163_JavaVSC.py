str = input()
answer = ""
for i, v in enumerate(str) :
    if (v == '_'):
        continue;
    elif( str[i-1] == '_') :
        answer += v.upper()
    elif( v >= 'A' and v <= 'Z') :
        answer += "_"
        answer += v.lower()
    else :
        answer += v
print(answer)
