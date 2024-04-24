package main

func minBitFlips(start int, goal int) int {
	return diff(toBin(start), toBin(goal))
}

func diff(a, b []byte) int {
	var (
		cnt = 0
		i   = 0
	)

	al, bl := len(a), len(b)
	for i < al && i < bl {
		if a[i] != b[i] {
			cnt++
		}
		i++
	}

	for i < al {
		if a[i] == 1 {
			cnt++
		}
		i++
	}

	for i < bl {
		if b[i] == 1 {
			cnt++
		}
		i++
	}

	return cnt
}

func toBin(n int) []byte {
	var res []byte
	for n > 0 {
		res = append(res, byte(n%2))
		n /= 2
	}

	return res
}
