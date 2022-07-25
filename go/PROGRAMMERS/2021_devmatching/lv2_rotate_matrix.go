package main

import "fmt"

func solution(rows int, columns int, queries [][]int) []int {
	result := []int{}
	for _, query := range queries {
		x1, y1 := query[0], query[1]
		result = append(result, (y1-1)*columns+(x1-1))
		//rotate(rows, columns, query[0], query[1], query[2], query[3])
	}
	return result
}

//func rotate(rows int, columns int, x1, y1, x2, y2 int) {
//	nums := []int{}
//	for y := y1; y <= y2; y++ {
//		for x := x1; x <= x2; x++ {
//			nums = append(nums, (y-1)*columns+(x-1))
//		}
//	}
//
//}

func main() {
	fmt.Printf("%+v", solution(6, 6, [][]int{{2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3}}))
}
