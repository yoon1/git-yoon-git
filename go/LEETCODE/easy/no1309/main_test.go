package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		input    string
		expected string
	}{
		{"10#11#12", "jkab"},
		{"1326#", "acz"},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := freqAlphabets(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
