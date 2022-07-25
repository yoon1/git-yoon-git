package main

import (
	"log"
	"strconv"
)

type Alpha struct {
	Number int
	Length int
}

var alphaMap = map[string]Alpha{
	"ze": {0, 4},
	"on": {1, 3},
	"tw": {2, 3},
	"th": {3, 5},
	"fo": {4, 4},
	"fi": {5, 4},
	"si": {6, 3},
	"se": {7, 5},
	"ei": {8, 5},
	"ni": {9, 4},
}

func solution(s string) int {
	res := 0
	length := len(s)
	idx := 0
	for idx < length {
		if s[idx] >= 48 && s[idx] <= 57 {
			val, _ := strconv.Atoi(string(s[idx]))
			res = (res * 10) + val
			idx++
			continue
		}
		alpha := alphaMap[s[idx:idx+2]]
		res = (res * 10) + alpha.Number
		idx += alpha.Length
	}

	return res
}

func main() {
	log.Println(solution("one4seveneight"))
}
