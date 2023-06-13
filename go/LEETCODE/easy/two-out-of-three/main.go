package two_out_of_three

func twoOutOfThree(nums1 []int, nums2 []int, nums3 []int) (res []int) {
	m := make(map[int]map[int]bool)
	xor := func(arr []int, i int) {
		for _, v := range arr {
			if _, ok := m[v]; !ok {
				m[v] = make(map[int]bool)
			}
			m[v][i] = true
		}
	}

	xor(nums1, 1)
	xor(nums2, 2)
	xor(nums3, 3)

	for i := 1; i <= 100; i++ {
		if len(m[i]) >= 2 {
			res = append(res, i)
		}
	}

	return
}
