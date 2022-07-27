package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_Solve(t *testing.T) {
	a := Solve(3, 3, Matrix{
		{1, 1, 1},
		{2, 2, 2},
		{0, 1, 0},
	}, Matrix{
		{3, 3, 3},
		{4, 4, 4},
		{5, 5, 100},
	})
	assert.Equal(t, a, Matrix{
		{4, 4, 4},
		{6, 6, 6},
		{5, 6, 100},
	})
}
