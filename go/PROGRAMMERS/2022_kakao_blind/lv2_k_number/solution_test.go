package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		n      int
		k      int
		answer int
	}{
		{437674, 3, 3},
		{110011, 10, 2},
	}

	for _, tc := range tcs {
		res := solution(tc.n, tc.k)
		assert.Equal(t, res, tc.answer)
	}
}

func Test_nToK(t *testing.T) {
	res := nToK(437674, 3)
	assert.Equal(t, res, "211020101011")
}
