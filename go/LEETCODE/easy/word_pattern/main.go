package main

import "strings"

func wordPattern(pattern string, s string) bool {
	var km = make(map[string]string)
	var vm = make(map[string]bool)

	search := func(k string, v string) string {
		if p, ok := km[k]; ok {
			return p
		} else {
			km[k] = v
			if _, ok := vm[v]; ok {
				return ""
			}
			vm[v] = true
			return v
		}
	}

	tokens := strings.Split(s, " ")
	if len(tokens) != len(pattern) {
		return false
	}

	for i, t := range pattern {
		if tokens[i] != search(string(t), tokens[i]) {
			return false
		}
	}

	return true
}
