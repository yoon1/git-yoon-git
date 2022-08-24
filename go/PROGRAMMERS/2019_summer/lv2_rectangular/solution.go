package lv2_rectangular

func gcd(min, max int) int {
	rem := min % max
	if rem == 0 {
		return max
	}

	return gcd(max, rem)
}

func minAndMax(a, b int) (int, int) {
	var min, max int
	if a > b {
		max = a
		min = b
	} else {
		max = b
		min = a
	}
	return min, max
}

func solution(w int, h int) int64 {
	min, max := minAndMax(w, h)
	v := gcd(min, max)
	a := max / v
	b := min / v

	return int64(w*h - ((a + (b - 1)) * v))
}
