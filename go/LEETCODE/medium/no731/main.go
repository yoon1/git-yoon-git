package main

import (
	"fmt"
	"log"
	"slices"
)

type MyCalendarTwo struct {
	startList []int
	endMap    map[int][]int
}

func Constructor() MyCalendarTwo {
	return MyCalendarTwo{startList: []int{}, endMap: make(map[int][]int)}
}

func (this *MyCalendarTwo) Book(start int, end int) bool {
	var scnt, ecnt = 1, 1
	for _, sc := range this.startList {
		for _, ec := range this.endMap[sc] {
			log.Println(sc, ec, start, end)
			if sc <= start && ec > start {
				scnt++
			}

			if sc < end && ec >= end {
				ecnt++
			}
		}
	}

	if scnt >= 3 || ecnt >= 3 {
		fmt.Println(this.startList, this.endMap, scnt, ecnt)
		return false
	}

	s, ok := slices.BinarySearch(this.startList, start)
	if !ok {
		this.startList = slices.Insert(this.startList, s, start)
	}

	this.endMap[start] = append(this.endMap[start], end)

	fmt.Println(this.startList, this.endMap, scnt, ecnt)

	return true
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}
