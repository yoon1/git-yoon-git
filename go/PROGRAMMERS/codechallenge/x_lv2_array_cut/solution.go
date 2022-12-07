package practices

func solution(n int, left int64, right int64) []int {
	arr := make([]int64, n*n)
	for i := int64(0); i < int64(n); i++ {
		// row
		for row := int64(0); row <= i; row++ {
			arr[n*int(row)+int(i)] = i + 1
		}

		// col
		for col := int64(0); col < i; col++ {
			arr[n*int(i)+int(col)] = i + 1
		}
	}

	return arr[left : right+1]
}
