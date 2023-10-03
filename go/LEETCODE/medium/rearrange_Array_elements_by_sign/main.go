package main

func rearrangeArray(nums []int) []int {
	var (
		res    = make([]int, len(nums))
		posIdx = 0
		negIdx = 1
	)

	for _, num := range nums {
		var idx *int
		if num > 0 {
			idx = &posIdx
		} else {
			idx = &negIdx
		}

		res[*idx] = num
		*idx += 2
	}

	return res
}
