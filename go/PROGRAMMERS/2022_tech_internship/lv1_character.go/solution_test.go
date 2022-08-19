package lv1_character_go

import (
	"github.com/stretchr/testify/assert"
	"log"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		survey        []string
		choices       []int
		expectedValue string
	}{
		{[]string{"AN", "CF", "MJ", "RT", "NA"}, []int{5, 3, 2, 7, 5}, "TCMA"},
		{[]string{"TR", "RT", "TR"}, []int{7, 1, 3}, "RCJA"},
	}

	for _, tc := range tcs {
		res := solution(tc.survey, tc.choices)
		assert.Equal(t, res, tc.expectedValue)
	}
}

func Test_reversePoint(t *testing.T) {
	log.Println(reversePoint(5))
}
