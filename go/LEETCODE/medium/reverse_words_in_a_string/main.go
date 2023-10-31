package main

import (
	"strings"
)

func reverseWords(s string) (res string) {
	splited := strings.Split(s, " ")
	for i := len(splited) - 1; i >= 0; i-- {
		if len(splited[i]) == 0 {
			continue
		}
		res += splited[i] + " "
	}

	res = res[:len(res)-1]
	return
}
