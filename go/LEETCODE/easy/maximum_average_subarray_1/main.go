package maximum_average_subarray_1

import "math"

func findMaxAverage(nums []int, k int) float64 {
	var (
		res    = float64(math.MinInt64)
		length = len(nums)
		avg    = func(start, end int) float64 {
			var sum int
			for i := start; i < end; i++ {
				sum += nums[i]
			}

			return float64(sum) / float64(end-start)
		}
	)

	for i := 0; i+k <= length; i++ {
		cur := avg(i, i+k)
		if cur > res {
			res = cur
		}
	}

	return res
}
