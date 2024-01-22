package main

import (
	"sort"
)

func frequencySort(s string) string {
	var m = make(map[int]int)
	for _, v := range s {
		m[int(v)]++
	}

	var keyValuePairs [][]int
	for k, v := range m {
		keyValuePairs = append(keyValuePairs, []int{k, v})
	}

	sort.Slice(keyValuePairs, func(i, j int) bool {
		return keyValuePairs[i][1] > keyValuePairs[j][1]
	})

	var res = ""
	for _, pair := range keyValuePairs {
		for i := 0; i < pair[1]; i++ {
			res += string(rune(pair[0]))
		}
	}

	return res
}
