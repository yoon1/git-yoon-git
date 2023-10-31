package main

import "strconv"

func minPartitions(n string) (max int) {
	for _, v := range n {
		i, _ := strconv.Atoi(string(v))
		if i > max {
			max = i
		}
	}

	return
}
