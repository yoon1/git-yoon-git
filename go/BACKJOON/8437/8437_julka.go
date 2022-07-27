package main

import (
	"fmt"
	"math/big"
)

func Solve(x, y *big.Int) (*big.Int, *big.Int) {
	a := new(big.Int)
	b := new(big.Int)
	a.Add(x, y)
	a.Div(a, big.NewInt(2))
	b.Sub(x, y)
	b.Div(b, big.NewInt(2))
	return a, b
}

func input() (*big.Int, *big.Int) {
	first := new(big.Int)
	second := new(big.Int)
	fmt.Scanln(first)
	fmt.Scanln(second)

	return first, second
}

func main() {
	a, b := Solve(input())
	fmt.Printf("%d\n%d", a, b)
}
