package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_Solve9177(t *testing.T) {
	tcs := []struct {
		Num    int
		Answer string
	}{
		{121, "yes"},
		{1231, "no"},
		{12421, "yes"},
	}

	for _, tc := range tcs {
		t.Run("PASS", func(t *testing.T) {
			res := Solve(tc.Num)
			assert.Equal(t, tc.Answer, res)
		})
	}
}
