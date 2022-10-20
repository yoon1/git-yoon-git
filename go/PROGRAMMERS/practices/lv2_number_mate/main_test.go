package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		X      string
		Y      string
		Answer string
	}{
		{"100", "2345", "-1"},
		{"100", "203045", "0"},
		{"100", "123450", "10"},
		{"12321", "42531", "321"},
		{"5525", "1255", "552"},
		{"99", "99", "99"},
	}

	for _, tc := range tcs {
		t.Run("ok", func(t *testing.T) {
			res := solution(tc.X, tc.Y)
			assert.Equal(t, tc.Answer, res)
		})
	}
}
