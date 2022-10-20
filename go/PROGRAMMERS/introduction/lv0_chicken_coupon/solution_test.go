package lv1_character_go

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		chicken       int
		expectedValue int
	}{
		//{100, 11},
		{1081, 120},
	}

	for _, tc := range tcs {
		res := solution(tc.chicken)
		assert.Equal(t, res, tc.expectedValue)
	}
}
