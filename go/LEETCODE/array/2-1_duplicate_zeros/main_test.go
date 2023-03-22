package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_duplicateZeros(t *testing.T) {
	tcs := []struct {
		input  []int
		output []int
	}{
		{[]int{1, 0, 2, 3, 0, 4, 5, 0}, []int{1, 0, 0, 2, 3, 0, 0, 4}},
		{[]int{1, 2, 3}, []int{1, 2, 3}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := duplicateZeros(tc.input)
			assert.Equal(t, tc.output, result)
		})
	}
}
