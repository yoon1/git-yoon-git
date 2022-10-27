package main

// Source: https://school.programmers.co.kr/learn/courses/30/lessons/131128

const (
	T = 3
)

var count int
var arr [T]int

func combination(nums *[]int, numLen, s, L int) {
	if L == T {
		if (*nums)[arr[0]]+(*nums)[arr[1]]+(*nums)[arr[2]] == 0 {
			count++
		}
		return
	}

	for idx := s; idx < numLen; idx++ {
		arr[L] = idx
		combination(nums, numLen, idx+1, L+1)
	}
}

func solution(number []int) int {
	length := len(number)
	combination(&number, length, 0, 0)

	return count
}
