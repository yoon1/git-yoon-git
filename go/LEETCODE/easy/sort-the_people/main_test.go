package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_sortPeople(t *testing.T) {
	tcs := []struct {
		names   []string
		heights []int
		output  []string
	}{
		{[]string{"Mary", "John", "Emma"}, []int{180, 165, 170}, []string{"Mary", "Emma", "John"}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := sortPeople(tc.names, tc.heights)
			assert.Equal(t, result, tc.output)
		})
	}
}
