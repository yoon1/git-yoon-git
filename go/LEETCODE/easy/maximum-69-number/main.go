package maximum_69_number

func maximum69Number(num int) int {
	var base = 1000
	for base > 0 {
		if (num/base)%10 == 6 {
			num += 3 * base
			break
		}
		base /= 10
	}

	return num
}
