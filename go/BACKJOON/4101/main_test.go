package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_Solve(t *testing.T) {
	tcs := []struct {
		N      int
		M      int
		Answer string
	}{
		{1, 19, "No"},
		{4, 4, "No"},
		{23, 14, "Yes"},
	}

	for _, tc := range tcs {
		t.Run("PASS", func(t *testing.T) {
			res := Solve(tc.N, tc.M)
			assert.Equal(t, tc.Answer, res)
		})
	}
}
