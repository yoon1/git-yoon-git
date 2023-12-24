package main

func createTargetArray(nums []int, index []int) []int {
	var (
		res    = []int{}
		length = len(nums)
	)
	for i := 0; i < length; i++ {
		res = append(res[:index[i]], append([]int{nums[i]}, res[index[i]:]...)...)
	}

	return res
}
