package lv2_rotate_matrix

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		rows          int
		columns       int
		queries       [][]int
		expectedValue []int
	}{
		{6, 6, [][]int{{2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3}}, []int{8, 10, 25}},
	}

	for _, tc := range tcs {
		res := solution(tc.rows, tc.columns, tc.queries)
		assert.Equal(t, res, tc.expectedValue)
	}
}
