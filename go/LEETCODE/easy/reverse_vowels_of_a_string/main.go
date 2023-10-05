package main

func reverseVowels(s string) string {
	var left, right = 0, len(s) - 1
	bytes := []byte(s)

	isVowel := func(b byte) bool {
		return b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u' ||
			b == 'A' || b == 'E' || b == 'I' || b == 'O' || b == 'U'
	}

	for left < right {
		for !isVowel(bytes[left]) && left < right {
			left++
		}

		for !isVowel(bytes[right]) && left < right {
			right--
		}

		bytes[left], bytes[right] = bytes[right], bytes[left]
		left++
		right--
	}

	return string(bytes)
}
