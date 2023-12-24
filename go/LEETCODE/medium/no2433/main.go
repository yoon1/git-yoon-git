package main

func findArray(pref []int) []int {
	var res = []int{pref[0]}
	for i := 1; i < len(pref); i++ {
		res = append(res, AxorX(pref[i-1], pref[i]))
	}

	return res
}

func AxorX(a, b int) int {
	return a ^ b
}
