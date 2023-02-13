package lv1_character_go

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		today     string
		terms     []string
		privacies []string
		answer    []int
	}{
		{"2022.05.19", []string{"A 6", "B 12", "C 3"}, []string{"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"}, []int{1, 3}},
		{"2020.01.01", []string{"Z 3", "D 5"}, []string{"2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"}, []int{1, 4, 5}},
	}

	for _, tc := range tcs {
		res := solution(tc.today, tc.terms, tc.privacies)
		assert.Equal(t, res, tc.answer)
	}
}
