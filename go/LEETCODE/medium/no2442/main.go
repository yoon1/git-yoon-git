package main

func countDistinctIntegers(nums []int) int {
	m := make(map[int]struct{}, len(nums)*2)
	for _, num := range nums {
		m[num] = struct{}{}
		m[reverse(num)] = struct{}{}
	}

	return len(m)
}

func reverse(num int) (res int) {
	for num > 0 {
		res = res*10 + num%10
		num /= 10
	}

	return res
}
