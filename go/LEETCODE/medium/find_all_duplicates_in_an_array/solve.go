package find_all_duplicates_in_an_array

func findDuplicates(nums []int) (res []int) {
	m := make(map[int]bool, len(nums))
	for _, num := range nums {
		if _, ok := m[num]; ok {
			res = append(res, num)
		} else {
			m[num] = true
		}
	}

	return
}
