package practices

func solution2(want []string, number []int, discount []string) int {
	res := 0

	m := make(map[string]int)
	for i, v := range want {
		m[v] = number[i]
	}

	length := len(discount) - 9
	for i := 0; i < length; i++ {
		if Cmp2(m, discount[i:i+10]) {
			res++
		}
	}

	return res
}

func Cmp2(target map[string]int, discount []string) bool {
	tm := make(map[string]int)
	for k, v := range target {
		tm[k] = v
	}

	for _, dc := range discount {
		if _, ok := tm[dc]; ok {
			tm[dc]--
			if tm[dc] <= 0 {
				delete(tm, dc)
			}
		}
		if len(tm) == 0 {
			return true
		}
	}

	return false
}
