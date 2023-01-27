package main

import "sort"

type Student struct {
	Id            int
	math, english int
	Total         int
}

func NewStudent(id, math, english int) *Student {
	return &Student{
		id, math, english, math + english,
	}
}

func solution(score [][]int) []int {
	rank := make([]int, len(score))
	students := []*Student{}
	for i, sc := range score {
		students = append(students, NewStudent(i, sc[0], sc[1]))
	}

	// sorting
	sort.Slice(students, func(i, j int) bool {
		return students[i].Total > students[j].Total
	})

	// rank
	pre := new(Student)
	for i, s := range students {
		r := i + 1
		if pre != nil && pre.Total == s.Total {
			r = rank[pre.Id]
		}
		rank[s.Id] = r
		pre = s
	}
	return rank
}
