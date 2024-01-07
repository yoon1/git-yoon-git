package main

func sumOfUnique(nums []int) int {
	m := make(map[int]int)
	for _, num := range nums {
		m[num]++
	}

	var res int
	for k, v := range m {
		if v == 1 {
			res += k
		}
	}

	return res
}
