package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_sortColors(t *testing.T) {
	tcs := []struct {
		input    string
		expected string
	}{
		{"leet**cod*e", "lecoe"},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := removeStars(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
