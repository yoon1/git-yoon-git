package main

func removeElement(nums []int, val int) int {
	p, q := 0, len(nums)-1
	if q == -1 {
		return 0
	}

	for p >= 0 && q >= 0 && p <= q {
		if nums[q] == val {
			q--
			continue
		}
		if nums[p] == val {
			t := nums[q]
			nums[q] = nums[p]
			nums[p] = t
			q--
		}
		p++
	}

	return p
}
