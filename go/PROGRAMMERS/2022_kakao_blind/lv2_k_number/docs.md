### isPrimNum
```go
for i := int64(2); i*i < n; i++ {
    if n%i == 0 {
        return false
    }
}
```
- 제곱근의 연산만큼만 수행하면 된다.
- 시간 초과(2진수 - 아주 긴 bigint number)

## 다른 풀이
- big.Int 함수 `ProbablyPrime` : 소수 가능성 판별
```go
func (x *Int) ProbablyPrime(n int) bool
```
