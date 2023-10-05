package main

import "sort"

type Person struct {
	name   string
	height int
}

func sortPeople(names []string, heights []int) []string {
	length := len(names)
	people := []Person{}
	for i := 0; i < length; i++ {
		people = append(people, Person{names[i], heights[i]})
	}

	sort.Slice(people, func(i, j int) bool {
		return people[i].height > people[j].height
	})

	for i := 0; i < length; i++ {
		names[i] = people[i].name
	}

	return names
}
