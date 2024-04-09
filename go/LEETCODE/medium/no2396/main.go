package main

func isStrictlyPalindromic(n int) bool {
	for i := 2; i <= n; i++ {
		if isPalindromicBase(n, i) == false {
			return false
		}
	}

	return true
}

func isPalindromicBase(n, b int) bool {
	stk := []int{}
	for n > 0 {
		v := n % b
		if len(stk) > 0 && stk[len(stk)-1] == v {
			stk = stk[:len(stk)-1]
		} else {
			stk = append(stk, v)
		}

		n /= b
	}
	return len(stk) == 0
}
