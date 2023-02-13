package main

import (
	"log"
	"strings"
)

type Profile struct {
	Id       int
	Name     string
	Reporter map[string]bool
}

func solution(id_list []string, report []string, k int) []int {
	points := make([]int, len(id_list))
	// init id map
	idMap := make(map[string]*Profile, len(id_list))
	for idx, name := range id_list {
		idMap[name] = &Profile{
			Id:       idx,
			Name:     name,
			Reporter: make(map[string]bool),
		}
	}

	// report
	for _, r := range report {
		slice := strings.Split(r, " ")
		reporter := idMap[slice[0]]
		reported := idMap[slice[1]]
		if _, ok := reported.Reporter[reporter.Name]; ok {
			continue
		}
		reported.Reporter[reporter.Name] = true
		length := len((reported).Reporter)
		log.Printf("LENGTH: %d\n", len(reported.Reporter))
		switch {
		case length == k:
			log.Println("case11", reporter.Id, reported.Id)
			for name := range reported.Reporter {
				log.Println("case1", reporter.Id, reported.Id)
				points[idMap[name].Id]++
			}
		case length > k:
			log.Println("case2", reporter.Id, reported.Id)
			points[reporter.Id]++
		}
	}

	return points
}

func main() {
	log.Println(solution(
		[]string{"muzi", "frodo", "apeach", "neo"},
		[]string{"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"},
		2))

	log.Println(solution([]string{"con", "ryan"}, []string{"ryan con", "ryan con", "ryan con", "ryan con"}, 3))
}
