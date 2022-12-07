package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_Solve9177(t *testing.T) {
	tcs := []struct {
		N      int
		M      int
		Answer int64
	}{
		{100, 6, 1192052400},
	}

	for _, tc := range tcs {
		t.Run("PASS", func(t *testing.T) {
			res := Solve(tc.N, tc.M)
			assert.Equal(t, tc.Answer, res)
		})
	}
}
