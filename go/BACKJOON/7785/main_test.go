package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_Solve(t *testing.T) {
	tcs := []struct {
		Inputs []string
		Answer map[string]bool
	}{
		{
			Inputs: []string{
				"Baha enter",
				"Askar enter",
				"Baha leave",
				"Artem enter",
			},
			Answer: map[string]bool{
				"Askar": true,
				"Artem": true,
			},
		},
	}

	for _, tc := range tcs {
		t.Run("PASS", func(t *testing.T) {
			res := Solve(tc.Inputs)
			assert.Equal(t, tc.Answer, res)
		})
	}
}
