package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func ScanInt() int64 {
	userVal, _ := r.ReadString('\n')
	input := strings.TrimSpace(userVal)
	n, _ := strconv.Atoi(input)
	return int64(n)
}

func ScanString() string {
	str, _ := r.ReadString('\n') // 여기서 text는 마지막에 줄바꿈 문자를 포함하므로
	str = strings.TrimSpace(str) // 줄바꿈 문자를 제거해야 함
	return str
}

func main() {
	n := ScanInt()
	ss := []string{}
	for i := int64(1); i <= n; i++ {
		s := ScanString()
		ss = append(ss, s)
	}

	namesMap := Solve(ss)
	sortKeys := make([]string, 0, len(namesMap))
	// 사전 순의 역순으로 정렬
	for k := range namesMap {
		sortKeys = append(sortKeys, k)
	}
	sort.Sort(sort.Reverse(sort.StringSlice(sortKeys)))

	for _, k := range sortKeys {
		fmt.Println(k)
	}
}

func Solve(ss []string) map[string]bool {
	nameMap := make(map[string]bool)
	for _, s := range ss {
		splited := strings.Split(s, " ")
		name, action := splited[0], splited[1]
		switch action {
		case "enter":
			nameMap[name] = true
		case "leave":
			if _, ok := nameMap[name]; ok {
				delete(nameMap, name)
			}
		}
	}

	return nameMap
}
