package two_out_of_three

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_sortPeople(t *testing.T) {
	tcs := []struct {
		num1   []int
		num2   []int
		num3   []int
		output []int
	}{
		{[]int{3, 1}, []int{2, 3}, []int{1, 2}, []int{2, 3, 1}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := twoOutOfThree(tc.num1, tc.num2, tc.num3)
			assert.Equal(t, tc.output, result)
		})
	}
}
