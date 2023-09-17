package main

import (
	"sort"
)

func sortVowels(s string) string {
	vowels := []int32{}
	idxes := []int{}

	res := []byte(s)
	for idx, r := range s {
		if isVowel(r) {
			vowels = append(vowels, r)
			idxes = append(idxes, idx)
		}
	}

	sort.Slice(vowels, func(i, j int) bool {
		return vowels[i] < vowels[j]
	})

	for i, idx := range idxes {
		res[idx] = byte(vowels[i])
	}

	return string(res)
}

func isVowel(r int32) bool {
	var vowels = "AEIOUaeiou"
	for _, c := range vowels {
		if c == r {
			return true
		}
	}

	return false
}
