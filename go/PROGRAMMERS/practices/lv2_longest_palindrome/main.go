package main

func isPalindrome(s string) bool {
	length := len(s)
	for i := 0; i < length/2; i++ {
		if s[i] != s[length-i-1] {
			return false
		}
	}
	return true
}

func solution(s string) int {
	length := len(s)
	for i := length; i > 0; i-- {
		for j := 0; j <= length-i; j++ {
			cur := s[j : i+j]
			if isPalindrome(cur) {
				return i
			}
		}
	}
	return 0
}
