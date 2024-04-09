package main

func sumOddLengthSubarrays(arr []int) int {
	length := len(arr)
	sum := 0
	for i := 1; i <= length; i += 2 {
		for j := 0; j <= length-i; j++ {
			for k := 0; k < i; k++ {
				sum += arr[j+k]
			}
		}
	}

	return sum
}
