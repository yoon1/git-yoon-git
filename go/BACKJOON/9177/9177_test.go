package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_Solve9177(t *testing.T) {
	tcs := []struct {
		One    string
		Two    string
		Three  string
		Answer bool
	}{
		//{"cat", "tree", "tcraete", true},
		//{"cat", "tree", "catrtee", true},
		//{"cat", "tree", "cttaree", false},
		//{"cat", "tree", "cttaree", false},
		//{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", true},
		//{"a", "aba", "aaba", true},
		//{"cat", "cat", "caatct", false},
		//{"aaaaaaaaaaaaaaa", "abaaaaaaaaaaaaa", "baaaaaaaaaaaaaaaaaaaaaaaaaaaaa", false},
		//{"catat", "tree", "catatreet", true},
		//{"a", "b", "ab", true},
		//{"aa", "b", "aba", true},
		//{"aa", "ab", "abaa", true},
		//{"abpa", "aba", "abuaaba", false},
		{"Abpc", "aba", "ABpacba", true},
	}

	for _, tc := range tcs {
		t.Run("PASS", func(t *testing.T) {
			res := Solve(tc.One, tc.Two, tc.Three)
			assert.Equal(t, res, tc.Answer)
		})
	}
}
