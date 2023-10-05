package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_sortVowels(t *testing.T) {
	tcs := []struct {
		s        string
		expected string
	}{
		{"lEetcOde", "lEOtcede"},
		{"lYmpH", "lYmpH"},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			res := sortVowels(tc.s)
			assert.Equal(t, res, tc.expected)
		})
	}
}
