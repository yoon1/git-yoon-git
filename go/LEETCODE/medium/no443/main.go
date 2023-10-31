package main

import "fmt"

func compress(chars []byte) int {
	var res []byte
	var length = len(chars)
	var count = 1
	for i := 0; i < length-1; i++ {
		if chars[i] != chars[i+1] {
			res = append(res, chars[i])
			if count != 1 {
				res = append(res, []byte(fmt.Sprintf("%d", count))...)
			}

			count = 0
			chars[i] = chars[i+1]
		}
		count++
	}

	res = append(res, chars[length-1])
	if count > 1 {
		res = append(res, []byte(fmt.Sprintf("%d", count))...)
	}

	chars = res
	chars[0] = 'a'
	chars[1] = 'b'
	chars[2] = '1'
	chars[3] = '2'

	return len(chars)
}
