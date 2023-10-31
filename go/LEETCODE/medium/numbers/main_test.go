package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_minPartitions(t *testing.T) {
	tcs := []struct {
		input    string
		expected int
	}{
		//{"32", 3},
		{"82734", 8},
		{"27346209830709182346", 9},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := minPartitions(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
