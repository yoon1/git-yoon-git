package main

//
//import (
//	"bufio"
//	"math"
//	"os"
//	"sort"
//	"strconv"
//	"strings"
//)
//
//const maxLen = 201
//
//var (
//	r = bufio.NewReader(os.Stdin)
//	w = bufio.NewWriter(os.Stdout)
//)
//
//func Solve(arr []int64) int64 {
//	// sort
//	sort.Slice(arr, func(i, j int) bool {
//		return arr[i] < arr[j]
//	})
//
//	length := len(arr)
//	min := math.MaxInt
//	for i := 0; i < length; i++ { // 현재 수를 기준으로 +4 한 수....(차감)
//		j := 0
//		for {
//			diff := arr[j] - arr[i]
//			if diff >= 4 {
//				break
//			}
//			if diff < min {
//
//			}
//			j++
//		}
//	}
//
//}
//
//func ScanInt() int64 {
//	userVal, _ := r.ReadString('\n')
//	input := strings.TrimSpace(userVal)
//	n, _ := strconv.Atoi(input)
//	return int64(n)
//}
//
//func main() {
//	n := ScanInt()
//	nums := []int64{}
//	for i := int64(1); i <= n; i++ {
//		c := ScanInt()
//		nums = append(nums, c)
//
//	}
//}
