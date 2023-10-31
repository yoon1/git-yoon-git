package main

func plusOne(digits []int) []int {
	idx := len(digits) - 1

	for idx >= 0 {
		digits[idx]++
		if digits[idx] < 10 {
			break
		}
		digits[idx] -= 10
		idx--
	}

	if idx == -1 {
		digits = append([]int{1}, digits...)
	}

	return digits
}
