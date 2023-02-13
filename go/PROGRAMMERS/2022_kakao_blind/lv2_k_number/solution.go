package main

import (
	"log"
	"strconv"
	"strings"
)

func solution(n int, k int) (res int) {
	b := nToK(n, k)
	ns := strings.Split(b, "0")
	log.Println(ns)
	for _, s := range ns {
		v, _ := strconv.ParseInt(s, 10, 32)
		if isPrimeNum(v) {
			log.Println(v)
			res++
		}
	}
	return
}

func nToK(n, k int) (res string) {
	for n > 0 {
		res = strconv.Itoa(n%k) + res
		n /= k
	}

	return res
}

func isPrimeNum(n int64) bool {
	if n <= 1 {
		return false
	}
	if n == 2 {
		return true
	}
	for i := int64(2); i*i < n; i++ {
		if n%i == 0 {
			return false
		}
	}

	return true
}
