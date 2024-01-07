package main

func groupThePeople(groupSizes []int) [][]int {
	var res [][]int
	var m = make(map[int][]int)

	for idx, gs := range groupSizes {
		m[gs] = append(m[gs], idx)

		if len(m[gs]) == gs {
			res = append(res, m[gs])
			delete(m, gs)
		}
	}

	return res
}
