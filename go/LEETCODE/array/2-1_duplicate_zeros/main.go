package main

func duplicateZeros(arr []int) []int {
	var length = len(arr)
	var i int
	for i < length {
		if arr[i] == 0 {
			t := make([]int, i+1)
			copy(t, arr[0:i+1])
			t = append(t, 0)
			t = append(t, arr[i+1:length-1]...)
			copy(arr, t)
			i++
		}
		i++
	}
	return arr
}
