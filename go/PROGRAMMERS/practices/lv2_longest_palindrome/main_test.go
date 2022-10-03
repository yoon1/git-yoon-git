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
		{"abcdcba", 7},
		{"abacde", 3},
	}

	for _, tc := range tcs {
		t.Run("ok", func(t *testing.T) {
			res := solution(tc.S)
			assert.Equal(t, tc.Answer, res)
		})
	}
}

func Test_isPalindrome(t *testing.T) {
	tcs := []struct {
		S      string
		Answer bool
	}{
		{"abcdcba", true},
	}

	for _, tc := range tcs {
		t.Run("ok", func(t *testing.T) {
			res := isPalindrome(tc.S)
			assert.Equal(t, tc.Answer, res)
		})
	}
}
