package lv2_two_queue

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		survey        []int
		choices       []int
		expectedValue int
	}{
		{[]int{3, 2, 7, 2}, []int{4, 6, 5, 1}, 2},
		{[]int{1, 2, 1, 2}, []int{1, 10, 1, 2}, 7},
		{[]int{1, 1}, []int{1, 5}, -1},
		{[]int{3, 3, 3, 3}, []int{3, 3, 21, 3}, 9},
	}

	for _, tc := range tcs {
		res := solution(tc.survey, tc.choices)
		assert.Equal(t, res, tc.expectedValue)
	}
}
