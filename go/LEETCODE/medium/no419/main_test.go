package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_triangularSum(t *testing.T) {
	tcs := []struct {
		board    [][]byte
		expected int
	}{
		{[][]byte{
			{'X', '.', '.', 'X'},
			{'.', '.', '.', 'X'},
			{'.', '.', '.', 'X'},
			{'.', '.', '.', '.'},
		}, 2},
		{[][]byte{{}}, 0},
		{[][]byte{{'X', '.', 'X'}}, 2},
		{[][]byte{
			{'X', '.', 'X', 'X'},
			{'.', '.', '.', '.'},
			{'X', '.', '.', 'X'},
			{'X', '.', '.', '.'},
		}, 4},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := countBattleships(tc.board)
			assert.Equal(t, tc.expected, result)
		})
	}
}
