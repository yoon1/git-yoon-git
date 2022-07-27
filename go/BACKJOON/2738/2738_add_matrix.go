package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	reader = bufio.NewReader(os.Stdin)
)

type Matrix [100][100]int

func inputMatrix(N, M int) Matrix {
	matrix := Matrix{}
	for i := 0; i < N; i++ {

		for j := 0; j < M; j++ {
			var num int
			fmt.Fscan(reader, &num)
			matrix[i][j] = num
		}
	}

	return matrix
}

func input() (int, int, Matrix, Matrix) {
	var N, M int
	fmt.Scanf("%d %d", &N, &M)
	a := inputMatrix(N, M)
	b := inputMatrix(N, M)
	return N, M, a, b
}

func print(N, M int, matrix Matrix) {
	for i := 0; i < N; i++ {
		for j := 0; j < M; j++ {
			fmt.Print(matrix[i][j], " ")
		}
		fmt.Println()
	}
}

func main() {
	N, M, a, b := input()
	res := Solve(N, M, a, b)
	print(N, M, res)
}

func Solve(N, M int, a, b Matrix) Matrix {
	res := [100][100]int{}
	for i := 0; i < N; i++ {
		for j := 0; j < M; j++ {
			res[i][j] = a[i][j] + b[i][j]
		}
	}

	return res
}
