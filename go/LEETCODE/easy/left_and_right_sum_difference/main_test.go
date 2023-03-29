package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_leftRigthDifference(t *testing.T) {
	tcs := []struct {
		input  []int
		answer []int
	}{
		{[]int{10, 4, 8, 3}, []int{15, 1, 11, 22}},
		{[]int{1}, []int{0}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := leftRightDifference(tc.input)
			assert.Equal(t, result, tc.answer)
		})
	}
}
