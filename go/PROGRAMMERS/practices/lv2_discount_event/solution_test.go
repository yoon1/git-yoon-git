package practices

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		want          []string
		number        []int
		discount      []string
		expectedValue int
	}{
		{[]string{"banana", "apple", "rice", "pork", "pot"}, []int{3, 2, 2, 2, 1}, []string{"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"}, 3},
		//{[]string{"apple"}, []int{10}, []string{"banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana"}, 0},
	}

	for _, tc := range tcs {
		res := solution(tc.want, tc.number, tc.discount)
		assert.Equal(t, res, tc.expectedValue)
	}
}
