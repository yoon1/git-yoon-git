package main

import (
	"fmt"
	"sort"
	"strings"
	"time"
)

func solution2(fees []int, records []string) []int {
	const layoutHHMM = "15:04"
	const lastTime = "23:59"
	baseTime, baseWon, unitTime, unitWon := fees[0], fees[1], fees[2], fees[3]
	park := make(map[string]string) // key: number, value: time
	useTime := make(map[string]int)
	for _, record := range records {
		r := strings.Split(record, " ")
		atTime, carNum, action := r[0], r[1], r[2]
		switch action {
		case "IN":
			park[carNum] = atTime
		case "OUT":
			if val, ok := park[carNum]; ok {
				inTime, _ := time.Parse(layoutHHMM, val)
				outTime, _ := time.Parse(layoutHHMM, atTime)
				useTime[carNum] += int(outTime.Sub(inTime).Minutes())
			}

			delete(park, carNum)
		}
	}

	// 남은 차량
	for carNum, val := range park {
		inTime, _ := time.Parse(layoutHHMM, val)
		outTime, _ := time.Parse(layoutHHMM, lastTime) // 23:59 last time
		useTime[carNum] += int(outTime.Sub(inTime).Minutes())
	}

	// 정산
	carKeys := []string{}
	for key := range useTime {
		carKeys = append(carKeys, key)
	}
	sort.Strings(carKeys)

	res := make([]int, 0, len(carKeys))
	for _, name := range carKeys {
		res = append(res, calcWon(baseTime, baseWon, unitTime, unitWon, useTime[name]))
	}

	return res
}

func calcWon(baseTime, baseWon, unitTime, unitWon, useTime int) int {
	won := baseWon
	useTime -= baseTime
	for useTime > 0 {
		useTime -= unitTime
		won += unitWon
	}

	return won
}

func main() {
	fmt.Printf("%+v", solution2([]int{180, 5000, 10, 600}, []string{"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"}))
}
