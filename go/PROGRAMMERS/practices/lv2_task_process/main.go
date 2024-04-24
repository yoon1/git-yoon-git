package main

import (
	"sort"
	"strconv"
	"strings"
)

type task struct {
	name     string
	remained int
}

func solution(plans [][]string) []string {
	//var remained []string
	var finished []string
	var stk []task

	sort.Slice(plans, func(i, j int) bool {
		return plans[i][1] < plans[j][1]
	})

	pre := plans[0][0]
	end := toMin(plans[0][1]) + toInt(plans[0][2])

	for i := 1; i < len(plans); i++ {
		cur := plans[i][0]
		curStart := toMin(plans[i][1])

		if curStart < end { // 만약 이게
			stk = append(stk, task{pre, end - curStart})
		} else {
			finished = append(finished, pre)
		}
		// 끝내고 남은 시간만큼 계속 해볼 수 있음. 그냥 끝내면 안됨..;

		for len(stk) > 0 && stk[len(stk)-1].remained {

		}

		pre = cur
	}

	finished = append(finished, pre)
	//finished = append(finished, remained...)

	return finished
}

func toMin(t string) int {
	sptd := strings.Split(t, ":")
	sh, sm := sptd[0], sptd[1]
	return toInt(sh)*60 + toInt(sm)
}

func toInt(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}
