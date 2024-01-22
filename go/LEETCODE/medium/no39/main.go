package main

func combinationSum(candidates []int, target int) [][]int {
	var backtracking func([]int, int)
	var length = len(candidates)
	var res [][]int

	// 후보를 우선 sorting
	backtracking = func(stk []int, idx int) {
		if idx >= length {
			return
		}

		s := sum(stk)
		if s == target {
			dst := make([]int, len(stk))
			copy(dst, stk)
			res = append(res, dst)
			return
		} else if s > target {
			return
		}

		stk = append(stk, candidates[idx])
		backtracking(stk, idx)
		stk = stk[:len(stk)-1]
		backtracking(stk, idx+1)
	}

	backtracking([]int{}, 0)

	return res
}

func sum(nums []int) int {
	var total int
	for _, num := range nums {
		total += num
	}

	return total
}
