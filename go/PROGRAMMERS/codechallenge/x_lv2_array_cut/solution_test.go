package practices

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		N      int
		Left   int64
		Right  int64
		Result []int
	}{
		{3, 2, 5, []int{3, 2, 2, 3}},
		{4, 7, 14, []int{4, 3, 3, 3, 4, 4, 4, 4}},
	}

	for _, tc := range tcs {
		t.Run("ok", func(t *testing.T) {
			res := solution(tc.N, tc.Left, tc.Right)
			assert.Equal(t, tc.Result, res)
		})
	}

}
