package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		candidates []int
		target     int
		expected   [][]int
	}{
		{[]int{2, 3, 6, 7}, 7, [][]int{{2, 2, 3}, {7}}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := combinationSum(tc.candidates, tc.target)
			assert.Equal(t, tc.expected, result)
		})
	}
}
