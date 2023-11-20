package main

func maximumNumberOfStringPairs(words []string) int {
	var res = 0
	for i, word := range words {
		if word[0] == word[1] {
			continue
		}

		if search(string(word[1])+string(word[0]), words[i+1:]) {
			res++
		}
	}

	return res
}

func search(key string, words []string) bool {
	for _, word := range words {
		if word == key {
			return true
		}
	}

	return false
}
