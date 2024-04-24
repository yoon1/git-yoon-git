package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		plans    [][]string
		expected []string
	}{
		//{[][]string{{"korean", "11:40", "30"}, {"english", "12:10", "20"}, {"math", "12:30", "40"}}, []string{"korean", "english", "math"}},
		{[][]string{{"aaa", "12:00", "30"}, {"bbb", "12:10", "30"}, {"ccc", "14:00", "30"}}, []string{"bbb", "aaa", "ccc"}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := solution(tc.plans)
			assert.Equal(t, tc.expected, result)
		})
	}
}
