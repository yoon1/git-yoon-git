package main

func solution(sequence []int, k int) []int {
	var (
		ll          = len(sequence)
		left, right = 0, 0
		sum         = 0
		res         = []int{0, 1000001}
	)

	for left < ll && right < ll {
		switch {
		case sum == k:
			if res[1]-res[0] > right-left ||
				(res[1]-res[0] == right-left && res[0] > left) {
				res[0], res[1] = left, right-1
			}
		case sum > k:
			sum -= sequence[left]
			left++
			continue
		}
		sum += sequence[right]
		right++
	}

	return res
}
