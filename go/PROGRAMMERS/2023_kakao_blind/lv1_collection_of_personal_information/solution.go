package lv1_character_go

import (
	"log"
	"strconv"
	"strings"
	"time"
)

// strToDate format: YYYY-MM-DD
func strToDate(str string) time.Time {
	dt, err := time.Parse("2006.01.02", str)
	if err != nil {
		log.Fatal(err)
	}

	return dt
}

func isExpired(today, registrationDate string, month int) bool {
	expiredDate := strToDate(registrationDate).AddDate(0, month, -1)
	if strToDate(today).After(expiredDate) {
		return true
	}
	return false
}

func solution(today string, terms []string, privacies []string) (res []int) {
	termMap := make(map[string]int)
	for _, term := range terms {
		splited := strings.Split(term, " ")
		tp := splited[0]
		expirationMonth, _ := strconv.Atoi(splited[1])
		termMap[tp] = expirationMonth
	}

	for i, privacy := range privacies {
		splited := strings.Split(privacy, " ")
		registrationDate := splited[0]
		tp := splited[1]
		if isExpired(today, registrationDate, termMap[tp]) {
			res = append(res, i+1)
		}
	}

	return
}
