# Learn

### 8437
1. bufio.Writer / Scanner를 사용하면 속도가 향상됨 => fmt는 느리다..
2. 큰 수를 다루는 `math/big` package


## 2738
line에서 int 배열를 추출하는 방법. (틀렸습니다로 뜨는 걸로 봐서는 문제의 문제인지 아래 코드의 문제인지 문제가 있는 것 같음.)
- ref: https://stackoverflow.com/questions/33017547/golang-scan-a-line-of-numbers-from-sdin
```  
text, _ := reader.ReadString('\n')
nums := strings.Split(text[0:len(text)-1], " ")
ary := make([]int, len(nums))
for i := range ary {
	ary[i], _ = strconv.Atoi(nums[i])
}
matrix = append(matrix, ary)
```