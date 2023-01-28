package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_same(t *testing.T) {
	tcs := []struct {
		S      string
		Answer int
	}{
		{"banana", 2},
	}

	for _, tc := range tcs {
		t.Run("ok", func(t *testing.T) {
			res := same(tc.S)
			assert.Equal(t, tc.Answer, res)
		})
	}
}

func Test_solution(t *testing.T) {
	tcs := []struct {
		S      string
		Answer int
	}{
		//{"banana", 3},
		{"abracadabra", 6},
		//{"aaabbaccccabba", 3},
	}

	for _, tc := range tcs {
		t.Run("ok", func(t *testing.T) {
			res := solution(tc.S)
			assert.Equal(t, tc.Answer, res)
		})
	}
}
