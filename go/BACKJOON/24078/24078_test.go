package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_Solve24078(t *testing.T) {
	tcs := []struct {
		Input  int
		Answer int
	}{
		{50, 8},
		{42, 0},
		{5, 5},
	}

	for _, tc := range tcs {
		t.Run("PASS", func(t *testing.T) {
			res := Solve(tc.Input)
			assert.Equal(t, res, tc.Answer)
		})
	}
}
