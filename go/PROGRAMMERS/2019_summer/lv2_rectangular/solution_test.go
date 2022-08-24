package lv2_rectangular

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		w             int
		h             int
		expectedValue int64
	}{
		{8, 12, 80},
	}

	for _, tc := range tcs {
		res := solution(tc.w, tc.h)
		assert.Equal(t, res, tc.expectedValue)
	}
}
