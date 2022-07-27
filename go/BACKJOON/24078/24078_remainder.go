package main

import (
	"fmt"
	"github.com/quiz.algorithm-solve/go/scanner"
)

func Solve(n int) int {
	return n % 21
}

func main() {
	fmt.Printf("%d", Solve(scanner.ScanInt()))
}
