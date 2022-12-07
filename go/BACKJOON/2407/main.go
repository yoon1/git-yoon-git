package main

import (
	"fmt"
	"log"
	"math/big"
)

var dp [102][102]int64

func Factorial(N int) *big.Int {
	if N <= 1 {
		return big.NewInt(1)
	}

	n := big.NewInt(int64(N))
	mul := new(big.Int)
	mul = mul.Mul(n, Factorial(N-1))
	return mul
}

func Solve(N, M int) *big.Int {
	n1 := Factorial(N)
	n2 := Factorial(M)
	n3 := Factorial(N - M)

	return n1.Div(n1, n2.Mul(n2, n3))
}

func main() {
	var N, M int
	fmt.Scanf("%d %d", &N, &M)
	log.Println(N, M)
	fmt.Printf("%s\n", Solve(N, M))
}
