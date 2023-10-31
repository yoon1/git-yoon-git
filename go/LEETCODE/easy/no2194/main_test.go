package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_sortColors(t *testing.T) {
	tcs := []struct {
		input    string
		expected []string
	}{
		{"K1:L2", []string{"K1", "K2", "L1", "L2"}},
		{"A1:F1", []string{"A1", "B1", "C1", "D1", "E1", "F1"}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := cellsInRange(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
