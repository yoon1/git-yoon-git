package maximum_average_subarray_1

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_findMaxAverage(t *testing.T) {
	tcs := []struct {
		nums     []int
		k        int
		expected float64
	}{
		{[]int{1, 12, -5, -6, 50, 3}, 4, 12.7500},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := findMaxAverage(tc.nums, tc.k)
			assert.Equal(t, result, tc.expected)
		})
	}
}
