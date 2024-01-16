package main

// stack
func removeOuterParentheses(s string) string {
	var (
		res  string
		l, r int
	)

	for _, ch := range s {
		var sc = string(ch)
		if sc == "(" {
			l++
		} else {
			r++
		}

		if l == r {
			l = 0
			r = 0
			continue
		}

		if l == 1 {
			continue
		}

		res += sc
	}

	return res
}
