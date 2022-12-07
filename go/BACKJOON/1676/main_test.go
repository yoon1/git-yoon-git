package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_Solve(t *testing.T) {
	tcs := []struct {
		N      int
		Answer int
	}{
		{10, 2},
		{3, 0},
	}

	for _, tc := range tcs {
		t.Run("PASS", func(t *testing.T) {
			res := Solve(tc.N)
			assert.Equal(t, tc.Answer, res)
		})
	}
}
