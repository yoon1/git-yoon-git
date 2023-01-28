package main

func same(s string) int {
	first := s[0]
	firstCount, otherCount := 0, 0
	for i := range s {
		if s[i] == first {
			firstCount++
		} else {
			otherCount++
		}

		if firstCount == otherCount {
			return i + 1
		}
	}
	return -1
}

func solution(s string) (res int) {
	length := len(s)
	for length > 0 {
		res++
		next := same(s)
		if next < 0 {
			break
		}
		s = s[next:]
		length = len(s)
	}
	return
}
