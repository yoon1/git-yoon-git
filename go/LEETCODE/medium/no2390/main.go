package main

func removeStars(s string) string {
	var res = make([]byte, 0, len(s))
	for i, v := range s {
		if string(v) != "*" {
			res = append(res, s[i])
		} else {
			res = res[:len(res)-1]
		}
	}

	return string(res)
}
