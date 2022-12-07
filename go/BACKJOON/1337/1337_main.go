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

func Solve(arr []int64) int {
	// sort
	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})

	min := 4
	length := len(arr)
	for i := 0; i < length; i++ {
		cnt := 4
		// 종료조건: i + 4
		j := 1
		start := arr[i]
		end := arr[i] + 4
		k := 0
		for i+j < length && end >= arr[i+j] && k < 5 {
			if i+j >= 0 && (start+int64(k) == arr[i+j]) {
				cnt--
				j++
			}
			k++
		}

		if min > cnt {
			min = cnt
		}
	}

	return min
}

func ScanInt() int64 {
	userVal, _ := r.ReadString('\n')
	input := strings.TrimSpace(userVal)
	n, _ := strconv.Atoi(input)
	return int64(n)
}

func main() {
	n := ScanInt()
	nums := []int64{}
	for i := int64(1); i <= n; i++ {
		c := ScanInt()
		nums = append(nums, c)
	}
	fmt.Printf("%d\n", Solve(nums))
}
