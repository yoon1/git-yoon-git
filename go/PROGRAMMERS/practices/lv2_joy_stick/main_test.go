package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_Main(t *testing.T) {
	tcs := []struct {
		S      string
		Answer int
	}{
		{"JEROEN", 56},
		{"JAN", 23},
	}

	for _, tc := range tcs {
		t.Run("ok", func(t *testing.T) {
			res := solution(tc.S)
			assert.Equal(t, tc.Answer, res)
		})
	}
}
