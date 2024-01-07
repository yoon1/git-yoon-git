package main

func groupThePeople(groupSizes []int) [][]int {
	var m = make(map[int][][]int)

	for _, v := range groupSizes {
		// 만약에 length 다 차면 새로 만들어서 채워 넣음.
		if arr, ok := m[v]; ok {
			length := len(arr)

		}
	}

	//var res = make(map[int])
	return m
}
