package main

import (
	"github.com/stretchr/testify/assert"
	"math/big"
	"testing"
)

func Test_Solve(t *testing.T) {
	a, b := Solve(big.NewInt(10), big.NewInt(2))
	assert.Equal(t, a, 6)
	assert.Equal(t, b, 4)
}
