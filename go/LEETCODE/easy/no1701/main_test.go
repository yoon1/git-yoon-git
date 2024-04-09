package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		input    [][]int
		expected float64
	}{
		//{[][]int{{1, 2}, {2, 5}, {4, 3}}, 5.00000},
		//{[][]int{{5, 2}, {5, 4}, {10, 3}, {20, 1}}, 3.25000},
		//{[][]int{{2, 3}, {6, 3}, {7, 5}, {11, 3}, {15, 2}, {18, 1}}, 4.16667},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := averageWaitingTime(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
