package main

func permute(nums []int) [][]int {
	var solution func(cur, n int)
	var l = len(nums)
	var res = [][]int{}

	solution = func(d, n int) {
		if d == n {
			var cp = make([]int, l)
			copy(cp, nums)
			res = append(res, cp)
		}

		for i := d; i < n; i++ {
			nums[d], nums[i] = nums[i], nums[d]
			solution(d+1, n)
			nums[d], nums[i] = nums[i], nums[d]
		}
	}

	solution(0, l)

	return res
}
