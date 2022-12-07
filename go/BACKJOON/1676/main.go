package main

import (
	"fmt"
	"math/big"
)

func Factorial(N int) *big.Int {
	if N <= 1 {
		return big.NewInt(1)
	}

	n := big.NewInt(int64(N))
	mul := new(big.Int)
	mul = mul.Mul(n, Factorial(N-1))
	return mul
}

func Solve(N int) int {
	n := Factorial(N).String()
	idx := len(n) - 1
	cnt := 0
	for idx >= 0 {
		if n[idx]-'0' != 0 {
			break
		}
		cnt++
		idx--
	}
	return cnt
}

func main() {
	var N int
	fmt.Scanf("%d", &N)
	fmt.Printf("%d\n", Solve(N))
}
