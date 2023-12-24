package main

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		input    []int
		expected []int
	}{
		{[]int{5, 2, 0, 3, 1}, []int{5, 7, 2, 3, 2}},
		{[]int{13}, []int{13}},
	}

	// A xor (A xor B) = B
	// (A xor A) xor (A xor B) = B
	// 1 xor (A xor B)

	//A 1010
	//B 1101
	//  0111
	//C xor A = 0111xor1010=1101

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := findArray(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}

func Test(t *testing.T) {
	fmt.Println(5 ^ 0)
}
