package main

func finalString(s string) string {
	var res string
	for i := 0; i < len(s); i++ {
		if s[i] == 'i' {
			res = reverseString(res)
			continue
		}
		res += string(s[i])
	}

	return res
}

func reverseString(str string) string {
	runes := []rune(str)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}
