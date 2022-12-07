package practices

import (
	"log"
	"testing"
	"time"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		want          []string
		number        []int
		discount      []string
		expectedValue int
	}{
		{[]string{"banana", "apple", "rice", "pork", "pot"}, []int{3, 2, 2, 2, 1}, []string{"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "pork", "pork", "pork", "pork", "pork", "pork", "pork", "pork", "pork", "pork", "pork", "pork", "pork", "pork", "pork"}, 0},
		//{[]string{"apple"}, []int{10}, []string{"banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana"}, 0},
	}

	for _, tc := range tcs {
		{
			startTime := time.Now()
			solution2(tc.want, tc.number, tc.discount)
			elapsedTime := time.Since(startTime)
			log.Println("solution2: ", elapsedTime)
		}

		{
			startTime := time.Now()
			solution(tc.want, tc.number, tc.discount)
			elapsedTime := time.Since(startTime)
			log.Println("solution: ", elapsedTime)
		}

	}
}
