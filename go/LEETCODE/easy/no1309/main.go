package main

import (
	"strconv"
	"strings"
)

func freqAlphabets(s string) string {
	res := ""
	splited := strings.Split(s, "#")
	wordLen := len(splited)
	for n, t := range splited {
		to := len(t)
		if n != wordLen-1 && to >= 2 {
			to -= 2
		}

		jtoz := ""
		for i := 0; i < to; i++ {
			res += string(t[i] + 48)
		}

		if n != wordLen-1 && len(t) >= 2 {
			i, _ := strconv.Atoi(t[len(t)-2:])
			jtoz = string(byte(i + 96))
		}
		res += jtoz
	}

	return res
}
